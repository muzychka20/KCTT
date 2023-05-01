import { defineConfig } from "vitepress";

export const nav = [
  { text: "Головна", link: "/" },
  { text: "Посібник", link: "/guide/what-is-kctt" },
  { text: "API", link: "/api/" },
];

export const sidebar = {
  "/guide/": [
    {
      text: "Введение",
      items: [
        { text: "Що таке KCTT?", link: "/guide/what-is-kctt" },
        { text: "Установка", link: "/guide/installation" },
      ],
    },
    {
      text: "Про проект",
      items: [
        { text: "Архітектура", link: "/guide/architecture" },
        { text: "Скріншоти", link: "/guide/screenshots" },
      ],
    },
  ],
  "/api/": [
    {
      text: "Utilities",
      items: [{ text: "UI.cpp", link: "/api/ui" }],
    },
    {
      text: "Users",
      items: [
        { text: "User.cpp", link: "/api/users/user" },
        { text: "Admin.cpp", link: "/api/users/user-admin" },
        { text: "Customer.cpp", link: "/api/users/user-customer" },
      ],
    },
    {
      text: "Stores",
      items: [
        { text: "UserStore.cpp", link: "/api/stores/user-store" },
        { text: "EventStore.cpp", link: "/api/stores/event-store" },
        { text: "TicketStore.cpp", link: "/api/stores/ticket-store" },
        { text: "GlobalStore.cpp", link: "/api/stores/global-store" },
      ],
    },
    {
      text: "Elements",
      items: [
        { text: "Event.cpp", link: "/api/elements/event" },
        { text: "Ticket.cpp", link: "/api/elements/ticket" },
      ],
    },
  ],
};

export default defineConfig({
  base: "/KCTT",
  title: "Keep Calm & Take Tickets",
  description: "Університетський проект ООП спрямований на отримання досвіду командної роботи.",
  themeConfig: {
    nav,
    sidebar,
    socialLinks: [{ icon: "github", link: "https://github.com/KyryloMuzychka/KCTT" }],
  },
});
