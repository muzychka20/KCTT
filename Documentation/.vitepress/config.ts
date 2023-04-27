import { defineConfig } from "vitepress";

export const nav = [
  { text: "Home", link: "/" },
  { text: "Examples", link: "/markdown-examples" },
];

export const sidebar = [
  {
    text: "Examples",
    items: [
      { text: "Markdown Examples", link: "/markdown-examples" },
      { text: "Runtime API Examples", link: "/api-examples" },
    ],
  },
];

export default defineConfig({
  base: "/KCTT",
  title: "Keep Calm & Take Tickets",
  description: "The university's OOP project is designed to gain experience in teamwork.",
  themeConfig: {
    nav,
    sidebar,
    socialLinks: [{ icon: "github", link: "https://github.com/KyryloMuzychka/KCTT" }],
  },
});
