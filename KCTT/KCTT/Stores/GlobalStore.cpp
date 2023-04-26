#include "./GlobalStore.h"
#include "../Users/Admin.h"
#include "../Users/Customer.h"
#include "./EventStore.h"
#include "./TicketStore.h"
#include "./UserStore.h"
#include <iostream>
#include <ostream>

User *GlobalStore::currectUser = nullptr;

void GlobalStore::InitUsersStore()
{
  UserStore *store = new UserStore();

  store->Add(new Admin("Kyrylo Muzychka", "kyrylo", "1"));
  store->Add(new Admin("Dmitry Tavern", "dmitry", "2"));
  store->Add(new Admin("Den Strateg", "den", "3"));
  store->Add(new Admin("Podion Boz", "rodion", "4"));
  store->Add(new Admin("Olga Kostrenko ", "olga", "5"));

  store->Add(new Customer("Customer #1", "custom1", "1"));
  store->Add(new Customer("Customer #2", "custom2", "1"));
  store->Add(new Customer("Customer #3", "custom3", "1"));

  GlobalStore::userStore = store;
}

void GlobalStore::InitEventStore()
{
  GlobalStore::eventStore = new EventStore();
}

void GlobalStore::InitTicketStore()
{
  GlobalStore::ticketStore = new TicketStore();
}

bool GlobalStore::IsAuthorizedUser()
{
  return GlobalStore::currectUser != nullptr;
}

void GlobalStore::SetAuthorizedUser(User *user)
{
  GlobalStore::currectUser = user;
}

User *GlobalStore::GetAuthorizedUser()
{
  return GlobalStore::currectUser;
}

UserStore *GlobalStore::GetUserStore()
{
  return GlobalStore::userStore;
}

EventStore *GlobalStore::GetEventStore()
{
  return GlobalStore::eventStore;
}

TicketStore *GlobalStore::GetTicketStore()
{
  return GlobalStore::ticketStore;
}
