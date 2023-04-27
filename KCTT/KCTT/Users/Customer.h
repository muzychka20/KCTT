#pragma once
#include "../Stores/TicketStore.h"
#include "User.h"
#include <vector>

class Customer : public User
{
public:
  Customer(std::string name, std::string login, std::string password);

  void PrintMenu(char *action) override;
  void ActivateMenu(char *action) override;

  void ToBuyTicket();
  void ToFindEventByName();
  void ToFindEventByDate();
  void ToCancelTicket();
  void ToPrintAllEvents();
  void ToPrintBoughtTickets();

private:
  TicketStore *boughtTickets;
};
