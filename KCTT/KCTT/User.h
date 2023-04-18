#pragma once
#include <iostream>

class User
{
private:
  std::string id;
  std::string name;
  std::string login;
  std::string password;
  std::string role;

public:
  User(std::string name, std::string password, std::string login);
  std::string GetId();
  std::string GetLogin();
  std::string GetPassword();
  std::string GetName();
  std::string GetRole();
  void SetName(std::string newName);
  void SetLogin(std::string newLogin);
  void SetPassword(std::string newPassword);
  void PrintMenu();
  void ActivateMenu();
  void ShowTickets();
  void ShowAllEvents();
  void AddTicket(Ticket ticket);
  void DeleteTicket(std::string ticketId);
  void FindEventByDate(std::string date);
  void FindEventByName(std::string name);
};
