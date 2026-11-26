// Live updates over a WebSocket with Supabase Realtime.
// Docs: https://supabase.com/docs/guides/realtime/postgres-changes
import { supabase } from './supabase.js';

export function subscribeToChanges({ onLocationChange, onSharesChange }) {
  const channel = supabase
    .channel('friends')
    .on(
      'postgres_changes',
      { event: '*', schema: 'public', table: 'locations' },
      onLocationChange,
    )
    .on(
      'postgres_changes',
      { event: '*', schema: 'public', table: 'shares' },
      onSharesChange,
    )
    .subscribe();

  return () => supabase.removeChannel(channel);
}
