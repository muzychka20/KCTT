#pragma once
#include "../Stores/TicketStore.h"
#include "User.h"
#include <string>
#include <vector>

class Customer : public User
{
public:
  Customer(std::string name, std::string login, std::string password);

  void PrintMenu(char *action) override;
  void ActivateMenu(char *action) override;

  void ToBuyTicket();
  void ToCancelTicket();
  void ToFindEventByName();
  void ToFindEventByDate();
  void ToPrintAllEvents();
  void ToPrintBoughtTickets();
};
