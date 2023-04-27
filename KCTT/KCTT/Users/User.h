#pragma once
#include "../Elements/Ticket.h"
#include <iostream>
#include <string>

class User
{
private:
  std::string id;
  std::string name;
  std::string login;
  std::string password;

protected:
  std::string role;

public:
  User(std::string name, std::string login, std::string password);
  std::string GetId();
  std::string GetRole();
  std::string GetName();
  std::string GetLogin();
  void SetName(std::string newName);
  void SetLogin(std::string newLogin);
  void SetPassword(std::string newPassword);
  bool ComparePassword(std::string password);
  virtual void PrintMenu(char *action);
  virtual void ActivateMenu(char *action);
};
