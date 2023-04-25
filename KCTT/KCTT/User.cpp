#include "./User.h"
#include "Ticket.h"
#include <iostream>
#include <ostream>

User::User(std::string name, std::string login, std::string password)
{
  this->name = name;
  this->login = login;
  this->password = password;
  this->role = "Default user";
}

std::string User::GetId()
{
  return this->id;
}

std::string User::GetLogin()
{
  return this->login;
}

std::string User::GetPassword()
{
  return this->password;
}

std::string User::GetName()
{
  return this->name;
}

std::string User::GetRole()
{
  return this->role;
}

void User::SetName(std::string newName)
{
  this->name = newName;
}

void User::SetLogin(std::string newLogin)
{
  this->login = newLogin;
}

void User::SetPassword(std::string newPassword)
{
  this->password = newPassword;
}

void User::PrintMenu(char *action)
{
  std::cout << "Menu not found." << std::endl;
  std::cout << "Your choice: ";
  std::cin >> *action;
}

void User::ActivateMenu(char *action)
{
  switch (*action)
  {
  default:
    std::cout << "Action not found." << std::endl;
    std::cout << "Enter to continue..." << std::endl;
    std::cin.ignore(10, '\n');
    std::cin.get();
    break;
  }
}

void User::ShowTickets()
{
  std::cout << "User.ShowTickets() not overloaded!" << std::endl;
}

void User::ShowAllEvents()
{
  std::cout << "User.ShowAllEvents() not overloaded!" << std::endl;
}

void User::AddTicket(Ticket ticket)
{
  std::cout << "User.AddTicket() not overloaded!" << std::endl;
}

void User::DeleteTicket(std::string ticketId)
{
  std::cout << "User.DeleteTicket() not overloaded!" << std::endl;
}

void User::FindEventByDate(std::string date)
{
  std::cout << "User.FindEventByDate() not overloaded!" << std::endl;
}

void User::FindEventByName(std::string name)
{
  std::cout << "User.FindEventByName() not overloaded!" << std::endl;
}
