#include "./User.h"

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

void User::PrintMenu()
{
}

void User::ActivateMenu()
{
}

void User::ShowTickets()
{
}

void User::ShowAllEvents()
{
}

void User::AddTicket(Ticket ticket)
{
}

void User::DeleteTicket(std::string ticketId)
{
}

void User::FindEventByDate(std::string date)
{
}

void User::FindEventByName(std::string name)
{
}
