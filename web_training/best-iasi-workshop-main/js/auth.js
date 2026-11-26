// Sign up, log in, log out with Supabase Auth (email + password).
// Docs: https://supabase.com/docs/reference/javascript/auth-signup
import { supabase } from "./supabase.js";

export async function signUp({ email, password, username }) {
  // TODO 3a: Create the account with supabase.auth.signUp().
  // Pass the username as extra user data: options: { data: { username } }.
  // A database trigger copies it into the "profiles" table.
  // Docs: https://supabase.com/docs/reference/javascript/auth-signup
  // Then delete the line below.
  // STUDENT: const { data, error } = { data: null, error: new Error('TODO 3b: sign up is not implemented yet') };
  // SOLUTION START
  throw new Error("Solution not implemented");
  // SOLUTION END

  if (error) {
    if (error.message.includes("Database error")) {
      throw new Error(
        "Could not create that account. The username may already be taken.",
      );
    }
    throw error;
  }

  return data.user;
}

export async function logIn({ email, password }) {
  // TODO 3b: Log the user in with their email and password.
  // Use the Supabase client imported at the top of this file. If Supabase
  // returns an error, throw it (the login form will show its message).
  // Return the logged-in user.
  // Docs: https://supabase.com/docs/reference/javascript/auth-signinwithpassword
  // STUDENT: throw new Error('TODO 3a: log in is not implemented yet');
  // SOLUTION START
  throw new Error("Solution not implemented");
  // SOLUTION END
}

export async function logOut() {
  const { error } = await supabase.auth.signOut();
  if (error) throw error;
}

export function onAuthChange(callback) {
  supabase.auth.onAuthStateChange((_, session) => {
    setTimeout(() => callback(session?.user ?? null), 0);
  });
}
