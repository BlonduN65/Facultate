import { ONLINE_THRESHOLD_MS } from './config.js';

export function isOnline(location) {
  if (!location) return false;
  return Date.now() - new Date(location.updatedAt).getTime() < ONLINE_THRESHOLD_MS;
}

export function timeAgo(isoDate) {
  const seconds = Math.round((Date.now() - new Date(isoDate).getTime()) / 1000);
  if (seconds < 60) return 'just now';
  const minutes = Math.round(seconds / 60);
  if (minutes < 60) return `${minutes} min ago`;
  const hours = Math.round(minutes / 60);
  if (hours < 24) return `${hours} h ago`;
  return `${Math.round(hours / 24)} days ago`;
}

export function colorFor(id) {
  let hash = 2166136261;
  for (const char of id) {
    hash = Math.imul(hash ^ char.charCodeAt(0), 16777619);
  }
  hash = Math.imul(hash ^ (hash >>> 16), 0x85ebca6b);
  hash = Math.imul(hash ^ (hash >>> 13), 0xc2b2ae35);
  hash ^= hash >>> 16;
  return `hsl(${(hash >>> 0) % 360}, 65%, 45%)`;
}
