#include "./GlobalStore.h"
#include <iostream>
#include <ostream>

User *GlobalStore::currectUser = nullptr;

User *GlobalStore::GetAuthorizedUser()
{
  return GlobalStore::currectUser;
}

void GlobalStore::SetAuthorizedUser(User *user)
{
  GlobalStore::currectUser = user;
}

bool GlobalStore::IsAuthorizedUser()
{
  return GlobalStore::currectUser != nullptr;
}