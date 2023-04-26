#pragma once
#include "../Elements/Event.h"
#include "Customer.h"
#include "User.h"
#include <string>

class Admin : public User
{
public:
  Admin(std::string name, std::string login, std::string password);
  void DeleteEvent(std::string id);
  void AddEvent(Event event);
  void EditEvent(std::string id);
  void DeleteAllTicketsByEvent(std::string eventId);
  void DeleteAllTickets();
  void AddCustomer(Customer customer);
  void DeleteCustomer(std::string id);
  void EditCustomer(std::string id);
  void ShowUsers();
  void PrintMenu(char *action) override;
  void ActivateMenu(char *action) override;
  void ShowTickets() override;
  void ShowAllEvents() override;
  void AddTicket(Ticket ticket) override;
  void DeleteTicket(std::string ticketId) override;
  void FindEventByDate(std::string date) override;
  void FindEventByName(std::string name) override;
};
