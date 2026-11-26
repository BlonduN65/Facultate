// Reading and writing our tables in the Supabase database.
// Docs: https://supabase.com/docs/reference/javascript/select
import { supabase } from './supabase.js';

export async function getProfile(userId) {
  const { data, error } = await supabase
    .from('profiles')
    .select('id, username')
    .eq('id', userId)
    .single();
  if (error) throw error;
  return data;
}

export async function saveMyLocation(userId, { lat, lng, accuracy }) {
  const { error } = await supabase
    .from('locations')
    .upsert({ user_id: userId, lat, lng, accuracy });
  if (error) throw error;
}

export async function getFriends(userId) {
  const { data, error } = await supabase
    .from('shares')
    .select('owner:profiles!shares_owner_id_fkey(id, username)')
    .eq('viewer_id', userId);
  if (error) throw error;
  return data.map((row) => row.owner);
}

export async function getFriendLocations(userId) {
  const { data, error } = await supabase
    .from('locations')
    .select('user_id, lat, lng, accuracy, updated_at')
    .neq('user_id', userId);
  if (error) throw error;
  return data.map(toLocation);
}

export function toLocation(row) {
  return {
    userId: row.user_id,
    lat: row.lat,
    lng: row.lng,
    accuracy: row.accuracy,
    updatedAt: row.updated_at,
  };
}

export async function getMyShares(userId) {
  const { data, error } = await supabase
    .from('shares')
    .select('viewer:profiles!shares_viewer_id_fkey(id, username)')
    .eq('owner_id', userId);
  if (error) throw error;
  return data.map((row) => row.viewer);
}

export async function shareWith(userId, username) {
  const { data: viewer, error: lookupError } = await supabase
    .from('profiles')
    .select('id')
    .eq('username', username.trim().toLowerCase())
    .maybeSingle();
  if (lookupError) throw lookupError;
  if (!viewer) throw new Error(`There's no user called "${username}".`);
  if (viewer.id === userId) throw new Error("You can't share with yourself.");

  const { error } = await supabase
    .from('shares')
    .insert({ owner_id: userId, viewer_id: viewer.id });

  if (error?.code === '23505') throw new Error(`You already share with ${username}.`);
  if (error) throw error;
}

export async function stopSharingWith(userId, viewerId) {
  const { error } = await supabase
    .from('shares')
    .delete()
    .eq('owner_id', userId)
    .eq('viewer_id', viewerId);
  if (error) throw error;
}
