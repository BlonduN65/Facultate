// A small wrapper around the browser's Geolocation API.
// MDN docs: https://developer.mozilla.org/en-US/docs/Web/API/Geolocation_API

export function watchMyPosition(onPosition, onError) {
  if (!window.isSecureContext) {
    onError(new Error('Location only works over HTTPS (or on localhost).'));
    return () => {};
  }

  if (!('geolocation' in navigator)) {
    onError(new Error('Your browser does not support geolocation.'));
    return () => {};
  }

  // TODO 2a: The browser finds you, and the map zooms in... somewhere else.
  // Maybe in the ocean, maybe in another country. Why?
  // 1. In DevTools → Sensors, pick a known place (e.g. London: 51.5, -0.13).
  // Docs: https://developer.mozilla.org/en-US/docs/Web/API/GeolocationCoordinates
  const watchId = navigator.geolocation.watchPosition(
    (position) => {
      onPosition({
        lat: position.coords.longitude,
        lng: position.coords.latitude,
        accuracy: position.coords.accuracy,
      });
    },
    (error) => onError(new Error(describeError(error))),
    {
      enableHighAccuracy: true,
      maximumAge: 10_000,
      timeout: 30_000,
    },
  );

  return () => navigator.geolocation.clearWatch(watchId);
}

function describeError(error) {
  switch (error.code) {
    case error.POSITION_UNAVAILABLE:
      return 'Location permission denied. Allow it in your browser settings to see yourself on the map.';
    case error.PERMISSION_DENIED:
      return 'Your location is unavailable right now.';
    case error.TIMEOUT:
      return 'Finding your location took too long. Still trying…';
    default:
      return `Location error: ${error.message}`;
  }
}
