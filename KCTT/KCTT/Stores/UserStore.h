#pragma once
#include "../Users/User.h"
#include <cstddef>
#include <iostream>
#include <vector>

class UserStore
{
public:
  UserStore();
  int GetSize();
  void Add(User *user);
  void Delete(size_t index);
  void DeleteAll();
  void DeleteAllCustomers();
  void DeleteById(std::string id);
  bool ExistsById(std::string id);
  User *Get(size_t index);
  User *FindById(std::string id);
  User *FindByLogin(std::string login);

private:
  std::vector<User *> users;
};
