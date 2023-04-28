import { defineConfig } from "vitepress";

export const nav = [
  { text: "Home", link: "/" },
  { text: "Guide", link: "/guide/what-is-kctt" },
  { text: "API", link: "/api/" },
];

export const sidebar = {
  "/guide/": [
    {
      text: "Введение",
      items: [
        { text: "Что такое KCTT?", link: "/guide/what-is-kctt" },
        { text: "Установка", link: "/guide/installation" },
      ],
    },
    {
      text: "Об проекте",
      items: [
        { text: "Начало", link: "/guide/get-started" },
        { text: "Архитектура", link: "/guide/architecture" },
        { text: "Скриншоты", link: "/guide/screenshots" },
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
  description: "The university's OOP project is designed to gain experience in teamwork.",
  themeConfig: {
    nav,
    sidebar,
    socialLinks: [{ icon: "github", link: "https://github.com/KyryloMuzychka/KCTT" }],
  },
});
