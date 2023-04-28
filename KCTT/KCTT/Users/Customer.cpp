#include "Customer.h"
#include "../Elements/Event.h"
#include "../Elements/Ticket.h"
#include "../Stores/EventStore.h"
#include "../Stores/GlobalStore.h"
#include "../Stores/TicketStore.h"
#include "../UI.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

Customer::Customer(std::string name, std::string login, std::string password)
    : User(name, login, password)
{
  this->role = "Customer";
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

  UI::PrintRow();
  UI::PrintTitle("Welcome customer!");
  UI::PrintRow();
  UI::PrintSimpleMenu(menu);
  std::cin >> *action;
}

void Customer::ActivateMenu(char *action)
{
  switch (*action)
  {
  case '1':
    this->ToBuyTicket();
    system("pause");
    break;

  case '2':
    this->ToFindEventByName();
    system("pause");
    break;

  case '3':
    this->ToFindEventByDate();
    system("pause");
    break;

  case '4':
    this->ToPrintAllEvents();
    system("pause");
    break;

  case '5':
    this->ToPrintBoughtTickets();
    system("pause");
    break;

  case '6':
    this->ToCancelTicket();
    system("pause");
    break;
  }
}

void Customer::ToBuyTicket()
{
  UI::PrintRow();
  UI::PrintTitle("Buy a ticket");
  UI::PrintRow();

  std::string ticketId;

  do
  {
    UI::EnterString("Enter ticket id: ", &ticketId);

    if (ticketId == "-")
    {
      break;
    }

    if (GlobalStore::GetTicketStore()->ExistsById(ticketId))
    {
      Ticket *ticket = GlobalStore::GetTicketStore()->FindById(ticketId);

      if (!ticket->IsBooked())
      {
        ticket->Booking(GlobalStore::GetAuthorizedUser()->GetId());
        std::cout << "Ticket success booked." << std::endl;
        break;
      }

      std::cout << "Ticket already booked." << std::endl;
      continue;
    }

    std::cout << "Ticket not found." << std::endl;
  } while (true);
}

void Customer::ToCancelTicket()
{
  UI::PrintRow();
  UI::PrintTitle("Cancel a ticket");
  UI::PrintRow();

  std::string ticketId;

  do
  {
    UI::EnterString("Enter ticket id: ", &ticketId);

    if (ticketId == "-")
    {
      break;
    }

    if (GlobalStore::GetTicketStore()->ExistsById(ticketId))
    {
      Ticket *ticket = GlobalStore::GetTicketStore()->FindById(ticketId);
      std::string userId = GlobalStore::GetAuthorizedUser()->GetId();

      if (ticket->IsBooked())
      {
        if (ticket->GetCustomerId() == userId)
        {
          ticket->Unbooking();
          std::cout << "Ticket success canceled." << std::endl;
          break;
        }

        std::cout << "You have not rights for this action." << std::endl;
        continue;
      }

      std::cout << "Ticket not booked." << std::endl;
      continue;
    }

    std::cout << "Ticket not found." << std::endl;
  } while (true);
}

void Customer::ToFindEventByName()
{
  UI::PrintRow();
  UI::PrintTitle("Find an event");
  UI::PrintRow();

  std::string name;

  UI::EnterString("Enter the name of the event: ", &name);

  std::vector<Event *> founded = GlobalStore::GetEventStore()->FindByName(name);

  if (!founded.empty())
  {
    for (int i = 0; i < founded.size(); i++)
    {
      UI::PrintEventTableRow(founded[i]);
    }

    UI::PrintRow();
  }
  else
  {
    std::cout << "Event not found for the name: " << name << std::endl;
  }
}

void Customer::ToFindEventByDate()
{
  UI::PrintRow();
  UI::PrintTitle("Find an event");
  UI::PrintRow();

  std::string date;

  UI::EnterString("Enter the name of the event: ", &date);

  std::vector<Event *> founded = GlobalStore::GetEventStore()->FindByDate(date);

  if (!founded.empty())
  {
    for (int i = 0; i < founded.size(); i++)
    {
      UI::PrintEventTableRow(founded[i]);
    }

    UI::PrintRow();
  }
  else
  {
    std::cout << "Event not found for the name: " << date << std::endl;
  }
}

void Customer::ToPrintAllEvents()
{
  UI::PrintRow();
  UI::PrintTitle("Available events");
  UI::PrintRow();

  int length = GlobalStore::GetEventStore()->GetSize();

  for (size_t index = 0; index < length; index++)
  {
    Event *event = GlobalStore::GetEventStore()->Get(index);
    UI::PrintEventTableRow(event);
  }

  UI::PrintRow();
}

void Customer::ToPrintBoughtTickets()
{
  UI::PrintRow();
  UI::PrintTitle("Bought tickets");
  UI::PrintRow();

  std::string userId = GlobalStore::GetAuthorizedUser()->GetId();
  std::vector<Ticket *> tickets =
      GlobalStore::GetTicketStore()->Filter({.customerId = userId});

  if (tickets.size() > 0)
  {
    for (size_t index = 0; index < tickets.size(); index++)
    {
      UI::PrintTicketTableRow(tickets[index]);
    }

    UI::PrintRow();
  }
  else
  {
    std::cout << "No tickets have been ordered yet." << std::endl;
  }
}
