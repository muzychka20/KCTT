#pragma once
#include "../Users/User.h"

class GlobalStore
{
public:
  static User *GetAuthorizedUser();
  static void SetAuthorizedUser(User *user);
  static bool IsAuthorizedUser();

private:
  static User *currectUser;
};
