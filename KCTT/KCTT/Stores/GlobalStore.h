#pragma once
#include "../Users/User.h"
#include "./EventStore.h"
#include "./TicketStore.h"
#include "./UserStore.h"

class GlobalStore
{
public:
  static void InitUsersStore();
  static void InitEventStore();
  static void InitTicketStore();
  static bool IsAuthorizedUser();
  static void SetAuthorizedUser(User *user);
  static User *GetAuthorizedUser();
  static UserStore *GetUserStore();
  static EventStore *GetEventStore();
  static TicketStore *GetTicketStore();

private:
  static User *currectUser;
  static UserStore *userStore;
  static EventStore *eventStore;
  static TicketStore *ticketStore;
};
