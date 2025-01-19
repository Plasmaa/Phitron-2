/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./templates/**/*.html", // template at project level
    "./**/templates/**/*.html", // templates inside app
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}

