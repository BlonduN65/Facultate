// Everything that touches the page's HTML (except the map) lives here.
import { colorFor, isOnline, timeAgo } from './utils.js';

// --- Toast notifications -----------------------------------------------------

let toastTimer;

export function showToast(message, kind = 'info') {
  const toast = document.querySelector('#toast');
  toast.textContent = message;
  toast.classList.toggle('is-error', kind === 'error');
  toast.hidden = false;
  clearTimeout(toastTimer);
  toastTimer = setTimeout(() => { toast.hidden = true; }, 5000);
}


export function showLoading() {
  document.querySelector('#loading').hidden = false;
  document.querySelector('#auth-form').hidden = true;
  document.querySelector('#session').hidden = true;
}

export function setLoggedIn(username) {
  const loggedIn = Boolean(username);
  document.querySelector('#loading').hidden = true;
  document.querySelector('#auth-form').hidden = loggedIn;
  document.querySelector('#session').hidden = !loggedIn;
  document.querySelector('#logout-btn').hidden = !loggedIn;
  document.querySelector('#username-label').textContent = username ?? '';
  if (!loggedIn) setAuthMode('login');
}

export function initControls({ onLogout, onLocate, onShare }) {
  document.querySelector('#logout-btn').addEventListener('click', onLogout);
  document.querySelector('#locate-btn').addEventListener('click', onLocate);

  const shareForm = document.querySelector('#share-form');
  shareForm.addEventListener('submit', async (event) => {
    event.preventDefault(); 
    const input = document.querySelector('#share-username');
    try {
      await onShare(input.value);
      input.value = '';
    } catch (error) {
      showToast(error.message, 'error');
    }
  });
}

let authMode = 'login';

export function initAuthForm({ onSubmit }) {
  const form = document.querySelector('#auth-form');

  document.querySelector('#auth-switch').addEventListener('click', (event) => {
    event.preventDefault();
    setAuthMode(authMode === 'login' ? 'signup' : 'login');
  });

  form.addEventListener('submit', async (event) => {
    event.preventDefault();
    const data = Object.fromEntries(new FormData(form));
    const submitButton = document.querySelector('#auth-submit');

    document.querySelector('#auth-error').textContent = '';
    submitButton.disabled = true;
    try {
      await onSubmit({ mode: authMode, ...data });
      form.reset();
    } catch (error) {
      document.querySelector('#auth-error').textContent = error.message;
    } finally {
      submitButton.disabled = false;
    }
  });
}

function setAuthMode(mode) {
  authMode = mode;
  const isSignup = mode === 'signup';
  document.querySelector('#auth-title').textContent = isSignup ? 'Sign up' : 'Log in';
  document.querySelector('#auth-submit').textContent = isSignup ? 'Sign up' : 'Log in';
  document.querySelector('#auth-switch').textContent = isSignup ? 'Already have an account? Log in' : 'No account yet? Sign up';
  document.querySelector('#username-field').hidden = !isSignup;
  document.querySelector('#username-field input').required = isSignup;
  document.querySelector('#username-field input').disabled = !isSignup;
  document.querySelector('#auth-form input[name="password"]').autocomplete = isSignup ? 'new-password' : 'current-password';
  document.querySelector('#auth-error').textContent = '';
}

export function renderFriends(friends, onFriendClick) {
  const list = document.querySelector('#friends-list');
  list.replaceChildren();

  if (friends.length === 0) {
    list.append(emptyItem('Nobody is sharing with you yet. Ask a friend to add your username!'));
    return;
  }

  const sorted = [...friends].sort((a, b) =>
    isOnline(b.location) - isOnline(a.location) || a.username.localeCompare(b.username));

  for (const friend of sorted) {
    const item = document.createElement('li');

    const dot = document.createElement('span');
    dot.className = isOnline(friend.location) ? 'status-dot is-online' : 'status-dot';
    dot.style.outline = `2px solid ${colorFor(friend.id)}`;

    const name = document.createElement('span');
    name.className = 'list__name';
    name.textContent = friend.username;

    const meta = document.createElement('span');
    meta.className = 'list__meta';
    if (!friend.location) meta.textContent = 'no location yet';
    else if (isOnline(friend.location)) meta.textContent = 'online';
    else meta.textContent = timeAgo(friend.location.updatedAt);

    item.append(dot, name, meta);

    if (friend.location) {
      item.classList.add('clickable');
      item.addEventListener('click', () => onFriendClick(friend));
    }

    list.append(item);
  }
}

export function renderShares(viewers, onStopSharing) {
  const list = document.querySelector('#shares-list');
  list.replaceChildren();

  if (viewers.length === 0) {
    list.append(emptyItem('You are not sharing your location with anyone.'));
    return;
  }

  for (const viewer of viewers) {
    const item = document.createElement('li');

    const name = document.createElement('span');
    name.className = 'list__name';
    name.textContent = viewer.username;

    const stop = document.createElement('button');
    stop.className = 'btn btn-small';
    stop.type = 'button';
    stop.textContent = 'Stop';
    stop.addEventListener('click', () => onStopSharing(viewer));

    item.append(name, stop);
    list.append(item);
  }
}

function emptyItem(text) {
  const item = document.createElement('li');
  item.className = 'empty';
  item.textContent = text;
  return item;
}
