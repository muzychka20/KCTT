#include "Customer.h"
#include "../Elements/Event.h"
#include "../Elements/Ticket.h"
#include "../Stores/EventStore.h"
#include "../Stores/TicketStore.h"
#include "../UI.h"
#include <iostream>
#include <stdio.h>

Customer::Customer(std::string name, std::string login, std::string password)
    : User(name, login, password)
{
  this->role = "Customer";
  this->boughtTickets = new TicketStore();
}

void Customer::PrintMenu(char *action)
{
  std::vector<std::string> menu = {
      "[1] Buy a ticket",
      "[2] Find an event by name",
      "[3] Find an event by date",
      "[4] View all events",
      "[5] View purchased tickets",
      "[6] Cancel a ticket",
      "--------------------------------------------------------",
      "[e] Logout",
  };

  UI::PrintTitle("Welcome customer!");
  UI::PrintSimpleMenu(menu);
  std::cin >> *action;
}

void Customer::ActivateMenu(char *action)
{
  std::string eventName, eventDate, row, place, id;
  bool isBooked;
  int choose = 0;

  switch (*action)
  {
  case '1':
    this->ToBuyTicket();
    break;

  case '2':
    this->ToFindEventByName();
    break;

  case '3':
    this->ToFindEventByDate();
    break;

  case '4':
    this->ToPrintAllEvents();
    break;

  case '5':
    this->ToPrintBoughtTickets();
    break;

  case '6':
    this->ToCancelTicket();
    break;
  }
}

void Customer::ToBuyTicket()
{
  UI::PrintTitle("Buy a ticket");

  std::cout << "In the process..." << std::endl;
}

void Customer::ToFindEventByName()
{
  UI::PrintTitle("Find an event");

  std::cout << "In the process..." << std::endl;
}

void Customer::ToFindEventByDate()
{
  UI::PrintTitle("Find an event");

  std::cout << "In the process..." << std::endl;
}

void Customer::ToCancelTicket()
{
  UI::PrintTitle("Cancel a ticket");

  std::cout << "In the process..." << std::endl;
}

void Customer::ToPrintAllEvents()
{
  UI::PrintTitle("Available events");

  std::cout << "In the process..." << std::endl;
}

void Customer::ToPrintBoughtTickets()
{
  UI::PrintTitle("Bought tickets");

  if (this->boughtTickets->GetSize() == 0)
  {
    std::cout << "No tickets have been ordered yet." << std::endl;
    return;
  }

  std::cout << "In the process..." << std::endl;
}
