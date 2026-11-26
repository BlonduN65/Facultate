// One shared Supabase client for the whole app.
// Docs: https://supabase.com/docs/reference/javascript/initializing
import { createClient } from 'https://cdn.jsdelivr.net/npm/@supabase/supabase-js@2.118.0/+esm';
import { SUPABASE_URL, SUPABASE_KEY } from './config.js';

export const isConfigured = !SUPABASE_URL.includes('YOUR-PROJECT-REF');

export const supabase = createClient(SUPABASE_URL, SUPABASE_KEY);
