# 📍 Find My Besties

A small web app that shows your live location on a map, along with the friends who share their location with you.

## Workshop links

- 📊 [Presentation slides](https://docs.google.com/presentation/d/105Ls3TH1tVDod59e1hOzrA0MUWA6poAvyRFvrt9svxk/edit?slide=id.g3abc664b05c_0_0#slide=id.g3abc664b05c_0_0)
- 📝 [Exercises: Deploy & HTTPS](https://forms.gle/M1uh8kiQE8qpJie47)
- 📝 [Exercises: Authentication](https://forms.gle/XN6fw758W59aH1eY7)
- 📝 [Exercises: Authorization](https://forms.gle/VsHuUUgsRxvqdGDb6)
- 💬 [Feedback form](https://forms.gle/Qqc9HCMzCvgeMWLV8)

Built with plain **HTML, CSS and JavaScript** (no frameworks, no build step) plus:

- [Leaflet](https://leafletjs.com/) + [OpenStreetMap](https://www.openstreetmap.org/) for the map
- the browser's [Geolocation API](https://developer.mozilla.org/en-US/docs/Web/API/Geolocation_API)
- [Supabase](https://supabase.com/) for login, the database and live updates
- [Netlify](https://www.netlify.com/) for hosting

## Run it locally

**Install once:** [Node.js](https://nodejs.org/en/download) (the **LTS** version) and a code editor such as [VS Code](https://code.visualstudio.com/download). The steps are the same on macOS, Windows and Linux, in any terminal (Terminal, PowerShell, the VS Code terminal…).

1. Download the code as a zip from this repository.
2. Unzip it and open the folder in your editor (in VS Code: *File → Open Folder…*).
3. Open a terminal in that folder (in VS Code: *Terminal → New Terminal*) and run:

```bash
npm install    # once: downloads the local web server
npm start      # every time: starts it
```

Then open http://localhost:8000. Stop the server with Ctrl+C.

No Node.js? Any static server works too: `python3 -m http.server 8000`, or the **Live Server** extension in VS Code ("Go Live").

## Connect to the database

The app stores accounts and locations in one **shared** [Supabase](https://supabase.com/) project, so everyone in the workshop appears in the same database. 

Open `js/config.js` and replace the two placeholders with the following values:

```js
export const SUPABASE_URL = 'https://jtqzllcfdqyuhpcxqfcr.supabase.co';
export const SUPABASE_KEY = 'sb_publishable_K_Ku5E3pEB1PtMvTg7SJYg_y2xwm7Rw';
```

Save, and refresh the page. Until you do this, the app shows a red "Supabase is not configured yet" message.

## Work through the TODOs

The code has numbered `TODO` comments for you to fill in. Until you solve them, they block parts of the app: the map is invisible or grey, there's no blue dot, the map zooms in on the wrong place, and log in and sign up say "not implemented".

To find them all, search the project for `TODO` (in VS Code: *Edit → Find in Files*, or Ctrl+Shift+F / Cmd+Shift+F).

## Further reading

Want to go deeper after the workshop? A few hand-picked links for each chapter.

### 1. The web developer's toolbox

- [What are browser developer tools?](https://developer.mozilla.org/en-US/docs/Learn_web_development/Howto/Tools_and_setup/What_are_browser_developer_tools) (MDN): a beginner tour of DevTools in every browser.
- [Chrome DevTools overview](https://developer.chrome.com/docs/devtools/overview): what each panel is for.
- [Console overview](https://developer.chrome.com/docs/devtools/console): reading errors, logging values and running JavaScript.
- [Download Node.js](https://nodejs.org/en/download): pick the **LTS** version.
- [Download VS Code](https://code.visualstudio.com/download)

### 2. HTML, CSS and the DOM

- [Document Object Model (DOM)](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model) (MDN): how the page becomes a tree that JavaScript can change.
- [The box model](https://developer.mozilla.org/en-US/docs/Learn_web_development/Core/Styling_basics/Box_model) (MDN): why an empty `<div>` has no height, plus padding, borders and margins.
- [View and change CSS](https://developer.chrome.com/docs/devtools/css): the Elements panel and live style editing.

### 3. Using other people's code

- [Leaflet Quick Start](https://leafletjs.com/examples/quick-start/): the guide used for the map exercise, and a good next step for markers and popups.
- [OpenStreetMap tile usage policy](https://operations.osmfoundation.org/policies/tiles/): what you agree to when you use someone else's free service.
- [Inspect network activity](https://developer.chrome.com/docs/devtools/network): the Network panel, step by step.

### 4. The browser can do that

- [Web APIs](https://developer.mozilla.org/en-US/docs/Web/API) (MDN): everything the browser can already do for you.
- [Geolocation API](https://developer.mozilla.org/en-US/docs/Web/API/Geolocation_API) (MDN): positions, options, errors and permissions.
- [Debug JavaScript](https://developer.chrome.com/docs/devtools/javascript): breakpoints, stepping and the Scope pane in the Sources panel.

### 5. Deploying and HTTPS

- [How the web works](https://developer.mozilla.org/en-US/docs/Learn_web_development/Getting_started/Web_standards/How_the_web_works) (MDN): clients, servers and what happens when you open a URL.
- [Secure contexts](https://developer.mozilla.org/en-US/docs/Web/Security/Defenses/Secure_Contexts) (MDN): why location and the camera only work on `https://` and `localhost`.
- [Remote debug Android devices](https://developer.chrome.com/docs/devtools/remote-debugging): use DevTools on the page running on your phone.

### 6. Authentication: who are you?

- [Supabase Auth](https://supabase.com/docs/guides/auth): how login, sessions and tokens work in Supabase.
- [Introduction to JSON Web Tokens](https://www.jwt.io/introduction): what's inside the token the browser stores.
- [Using promises](https://developer.mozilla.org/en-US/docs/Learn_web_development/Extensions/Async_JS/Promises) (MDN): `async`, `await` and waiting for the server.

### 7. Authorization and live updates

- [Row Level Security](https://supabase.com/docs/guides/database/postgres/row-level-security) (Supabase): the database rules that decide who sees which rows.
- [Postgres Changes](https://supabase.com/docs/guides/realtime/postgres-changes) (Supabase): listening to database changes live.
- [The WebSocket API](https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API) (MDN): the open connection that carries those live updates.
