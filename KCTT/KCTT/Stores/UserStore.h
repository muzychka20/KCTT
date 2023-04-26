#pragma once
#include "../Users/User.h"
#include <iostream>
#include <vector>

class UserStore
{
public:
  static std::vector<User *> users;
};
