#pragma once
#include <vector>
#include "./User.h"


class UserStore {
public:
  static std::vector<User *> users;
};
