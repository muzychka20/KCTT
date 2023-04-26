#pragma once
#include "../Elements/Ticket.h"
#include "User.h"
#include <vector>

class Customer : public User
{
public:
  std::vector<Ticket> boughtTickets;
  Customer(std::string name, std::string login, std::string password);
  void PrintMenu(char *action) override;
  void ActivateMenu(char *action) override;
  void ShowTickets() override;
  void ShowAllEvents() override;
  void AddTicket(Ticket ticket) override;
  void DeleteTicket(std::string ticketId) override;
};
