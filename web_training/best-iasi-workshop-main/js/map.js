// Everything that touches the Leaflet map lives here.
// Leaflet docs: https://leafletjs.com/reference.html
import { colorFor, isOnline, timeAgo } from './utils.js';

// Leaflet is loaded by a <script> tag in index.html, which stores the whole
// library in a global variable called `L` (that's the name the Leaflet docs
// use). 
const leaflet = window.L;

let map;
let myMarker;
let myAccuracyCircle;
const friendMarkers = new Map();

export function initMap() {
  map = leaflet.map('map', { zoomControl: false }).setView([20, 0], 2);

  // TODO 2: The map is grey. It has no images ("tiles") yet.
  // Follow the Leaflet Quick Start guide to add an OpenStreetMap tile layer
  // to `map`. Don't forget the attribution: OpenStreetMap requires it.
  // Docs: https://leafletjs.com/examples/quick-start/

  leaflet.control.zoom({ position: 'bottomright' }).addTo(map);
}

export function showMyLocation({ lat, lng, accuracy }) {
  const latLng = [lat, lng];

  if (!myMarker) {
    // TODO 2 (bonus): You should see a blue dot (#2563eb) with a white border,
    // 8px wide, where you are. The map zooms in, but there's no dot!
    // The marker IS on the map: find it in DevTools → Elements (an SVG <path>
    // inside .leaflet-overlay-pane) and look at its attributes.
    // Then fix the options below. There's more than one problem.
    // Docs: https://leafletjs.com/reference.html#circlemarker (and the Path options)
    myMarker = leaflet.circleMarker(latLng, {
      radius: 0,
      color: 'transparent',
      weight: 3,
      fillColor: '',
      fillOpacity: 0,
    }).addTo(map);

    map.setView(latLng, 16);
  } else {
    const wasVisible = map.getBounds().contains(myMarker.getLatLng());

    myMarker.setLatLng(latLng);
    myAccuracyCircle?.setLatLng(latLng).setRadius(accuracy);

    if (wasVisible && !map.getBounds().contains(latLng)) {
      map.panTo(latLng);
    }
  }
}

export function hasMyLocation() {
  return Boolean(myMarker);
}

export function centerOnMe() {
  if (myMarker) map.flyTo(myMarker.getLatLng(), 16);
}

export function flyTo(lat, lng) {
  map.flyTo([lat, lng], 16);
}

export function syncFriendMarkers(friends) {
  const seen = new Set();

  for (const friend of friends) {
    if (!friend.location) continue;
    seen.add(friend.id);

    const { lat, lng } = friend.location;
    let marker = friendMarkers.get(friend.id);

    if (!marker) {
      marker = leaflet.marker([lat, lng]).addTo(map);
      marker.bindPopup((layer) => friendPopup(layer.friend));
      friendMarkers.set(friend.id, marker);
    } else {
      marker.setLatLng([lat, lng]);
    }

    marker.friend = friend;
    marker.setIcon(friendIcon(friend));
  }

  for (const [id, marker] of friendMarkers) {
    if (!seen.has(id)) {
      marker.remove();
      friendMarkers.delete(id);
    }
  }
}

function friendIcon(friend) {
  const pin = document.createElement('div');
  pin.className = isOnline(friend.location) ? 'friend-pin' : 'friend-pin is-offline';
  pin.style.setProperty('--pin-color', colorFor(friend.id));

  const initial = document.createElement('span');
  initial.className = 'friend-pin__initial';
  initial.textContent = friend.username[0].toUpperCase();

  const name = document.createElement('span');
  name.className = 'friend-pin__name';
  name.textContent = friend.username;

  pin.append(initial, name);

  return leaflet.divIcon({
    html: pin,
    className: 'friend-pin-wrapper',
    iconSize: [36, 36],
    iconAnchor: [18, 18],
    popupAnchor: [0, -20],
  });
}

function friendPopup(friend) {
  const el = document.createElement('div');
  const name = document.createElement('strong');
  name.textContent = friend.username;
  const details = document.createElement('div');
  const accuracy = Math.round(friend.location.accuracy ?? 0);
  details.textContent = `Updated ${timeAgo(friend.location.updatedAt)} · ±${accuracy} m`;
  el.append(name, details);
  return el;
}
