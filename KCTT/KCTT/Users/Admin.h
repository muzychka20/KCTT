#pragma once
#include "../Elements/Event.h"
#include "Customer.h"
#include "User.h"
#include <string>

class Admin : public User
{
public:
  Admin(std::string name, std::string login, std::string password);

  void PrintMenu(char *action) override;
  void ActivateMenu(char *action) override;

  void ToPrintEvents();
  void ToAddEvent();
  void ToEditEvent();
  void ToDeleteEvent();

  void ToPrintTickets();
  void ToAddTicket();
  void ToEditTicket();
  void ToDeleteTicket();
  void ToDeleteTicketByEvent();

  void ToPrintCustomers();
  void ToAddCustomer();
  void ToEditCustomer();
  void ToDeleteCustomer();

  void ToClearEvents();
  void ToClearTickets();
  void ToClearCustomers();
};
