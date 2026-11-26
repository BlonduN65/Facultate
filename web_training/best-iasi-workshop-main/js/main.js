import * as api from './api.js';
import { logIn, logOut, onAuthChange, signUp } from './auth.js';
import { HEARTBEAT_MS, UPLOAD_INTERVAL_MS } from './config.js';
import { watchMyPosition } from './geo.js';
import { centerOnMe, flyTo, hasMyLocation, initMap, showMyLocation, syncFriendMarkers } from './map.js';
import { subscribeToChanges } from './realtime.js';
import { isConfigured } from './supabase.js';
import * as ui from './ui.js';

const state = {
  user: null,
  myPosition: null,
  lastUploadAt: 0,
  friends: new Map(),
  stopRealtime: null,
  heartbeatTimer: null,
};

initMap();

watchMyPosition(
  (position) => {
    state.myPosition = position;
    showMyLocation(position);
    uploadMyLocation();
  },
  (error) => {
    if (state.myPosition) return;
    ui.showToast(error.message, 'error');
  },
);

ui.initControls({
  onLogout: handleLogout,
  onLocate: () => {
    if (hasMyLocation()) centerOnMe();
    else ui.showToast("We don't know where you are yet.");
  },
  onShare: async (username) => {
    await api.shareWith(state.user.id, username);
    ui.showToast(`${username} can now see your location.`);
    await loadShares();
  },
});

ui.initAuthForm({
  onSubmit: async ({ mode, email, password, username }) => {
    if (mode === 'signup') {
      await signUp({ email, password, username: username.toLowerCase() });
    } else {
      await logIn({ email, password });
    }
  },
});

if (isConfigured) {
  onAuthChange(async (user) => {
    if (!user) {
      if (state.user) endSession();
      else ui.setLoggedIn(null);
      return;
    }
    if (user.id === state.user?.id) return;
    if (state.user) endSession();
    await startSession(user);
  });
} else {
  ui.setLoggedIn(null);
  ui.showToast('Supabase is not configured yet: fill in js/config.js (see README).', 'error');
}

async function startSession(user) {
  state.user = user;
  ui.showLoading();

  try {
    const profile = await api.getProfile(user.id);
    await Promise.all([loadFriends(), loadShares()]);
    ui.setLoggedIn(profile.username);
  } catch (error) {
    ui.setLoggedIn(user.email);
    ui.showToast(`Could not load your data: ${error.message}`, 'error');
  }

  state.stopRealtime = subscribeToChanges({
    onLocationChange: handleLocationChange,
    onSharesChange: () => refreshFriendsAndShares(),
  });

  state.heartbeatTimer = setInterval(() => {
    uploadMyLocation({ force: true });
    renderFriends();
  }, HEARTBEAT_MS);

  uploadMyLocation({ force: true });
}

function endSession() {
  state.stopRealtime?.();
  state.stopRealtime = null;
  clearInterval(state.heartbeatTimer);
  state.user = null;
  state.friends.clear();
  renderFriends();
  ui.setLoggedIn(null);
}

async function handleLogout() {
  try {
    await logOut();
  } catch (error) {
    ui.showToast(error.message, 'error');
  }
}

async function uploadMyLocation({ force = false } = {}) {
  if (!state.user || !state.myPosition) return;

  const now = Date.now();
  if (!force && now - state.lastUploadAt < UPLOAD_INTERVAL_MS) return;
  state.lastUploadAt = now;

  try {
    await api.saveMyLocation(state.user.id, state.myPosition);
  } catch (error) {
    ui.showToast(`Could not share your location: ${error.message}`, 'error');
  }
}

async function loadFriends() {
  if (!state.user) return;
  const [friends, locations] = await Promise.all([
    api.getFriends(state.user.id),
    api.getFriendLocations(state.user.id),
  ]);

  state.friends = new Map(friends.map((friend) => [friend.id, { ...friend, location: null }]));
  for (const location of locations) {
    const friend = state.friends.get(location.userId);
    if (friend) friend.location = location;
  }
  renderFriends();
}

async function loadShares() {
  if (!state.user) return;
  const viewers = await api.getMyShares(state.user.id);
  ui.renderShares(viewers, async (viewer) => {
    try {
      await api.stopSharingWith(state.user.id, viewer.id);
      ui.showToast(`${viewer.username} can no longer see your location.`);
      await loadShares();
    } catch (error) {
      ui.showToast(error.message, 'error');
    }
  });
}

async function refreshFriendsAndShares() {
  try {
    await Promise.all([loadFriends(), loadShares()]);
  } catch (error) {
    ui.showToast(`Could not refresh friends: ${error.message}`, 'error');
  }
}

function handleLocationChange(payload) {
  if (payload.eventType === 'DELETE') {
    const friend = state.friends.get(payload.old.user_id);
    if (friend) friend.location = null;
  } else {
    const location = api.toLocation(payload.new);
    if (location.userId === state.user?.id) return;
    const friend = state.friends.get(location.userId);
    if (!friend) return refreshFriendsAndShares();
    friend.location = location;
  }
  renderFriends();
}

function renderFriends() {
  const friends = [...state.friends.values()];
  syncFriendMarkers(friends);
  ui.renderFriends(friends, (friend) => flyTo(friend.location.lat, friend.location.lng));
}
