#pragma once
#include <iostream>
#include "./Ticket.h"

class User {
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
  std::string GetLogin();
  std::string GetPassword();
  std::string GetName();
  std::string GetRole();
  void SetName(std::string newName);
  void SetLogin(std::string newLogin);
  void SetPassword(std::string newPassword);
  virtual void PrintMenu(char *action);
  virtual void ActivateMenu(char *action);
  virtual void ShowTickets();
  virtual void ShowAllEvents();
  virtual void AddTicket(Ticket ticket);
  virtual void DeleteTicket(std::string ticketId);
  virtual void FindEventByDate(std::string date);
  virtual void FindEventByName(std::string name);
};
