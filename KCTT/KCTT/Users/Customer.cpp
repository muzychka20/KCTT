#include "Customer.h"
#include "../Elements/Event.h"
#include "../Elements/Ticket.h"
#include "../Stores/EventStore.h"
#include "../Stores/TicketStore.h"
#include <iostream>
#include <stdio.h>

Customer::Customer(std::string name, std::string login, std::string password)
    : User(name, login, password)
{
  this->role = "Customer";
}

void Customer::PrintMenu(char *action)
{
  std::cout << "\t Welcome customer!" << std::endl;
  std::cout << "      Please select an action:" << std::endl;
  std::cout << "  1. Buy a ticket" << std::endl;
  std::cout << "  2. Find an event by name" << std::endl;
  std::cout << "  3. Find an event by date" << std::endl;
  std::cout << "  4. View all events " << std::endl;
  std::cout << "  5. View purchased tickets" << std::endl;
  std::cout << "  6. Cancel a ticket" << std::endl;
  std::cout << "  Enter your choice (1-6): ";
  std::cin >> *action;
}

void Customer::ActivateMenu(char *action)
{
  std::string eventName, eventDate, row, place, id;
  bool isBooked;
  int choose = 0;
  system("cls");
  switch (*action)
  {
  case '1': {
    ShowAllEvents();
    std::cout << "Which event would you like to attend. Enter the name of the "
                 "event: ";
    std::cin >> eventName;

    bool eventExists = false;
    for (size_t i = 0; i < EventStore::events.size(); ++i)
    {
      if (EventStore::events[i].name == eventName)
      {
        EventStore::events[i].ShowEvent();
        eventExists = true;
        break;
      }
    }

    if (eventExists)
    {

      std::cout << "The event exists.Do you want to buy a ticket?(1/0): ";
      std::cin >> choose;
      if (choose == 1)
      {

        std::cout << "Choose the row: ";
        std::cin >> row;
        std::cout << "Choose the place: ";
        std::cin >> place;

        for (int i = 0; i < TicketStore::tickets.size(); ++i)
        {
          if (TicketStore::tickets[i].getRow() == row &&
              TicketStore::tickets[i].getPlace() == place)
          {
            TicketStore::tickets[i].Booking();
            boughtTickets.push_back(TicketStore::tickets[i]);
            break;
          }
        }
      };
      if (choose == 0)
        std::cout << "You don't want to buy a ticket.";
    }
    else
    {
      std::cout << "The event does not exist." << std::endl;
    }
    break;
  }
  case '2': {
    std::cout
        << "Which event would you like to find. Enter the name of the event: ";
    std::cin >> eventName;
    FindEventByName(eventName);

    bool eventExists = false;
    for (size_t i = 0; i < EventStore::events.size(); i++)
    {
      if (EventStore::events[i].name == eventName)
      {
        eventExists = true;
        break;
      }
    }
    if (eventExists)
    {
      std::cout << "The event exists." << std::endl;
    }
    else
    {
      std::cout << "The event does not exist." << std::endl;
    }
    break;
  }
  case '3': {
    std::cout
        << "When would you like to attend event. Enter the date of the event: ";
    std::cin >> eventDate;
    FindEventByDate(eventDate);

    bool eventExists = false;
    for (size_t i = 0; i < EventStore::events.size(); i++)
    {
      if (EventStore::events[i].date == eventDate)
      {
        eventExists = true;
        break;
      }
    }
    if (eventExists)
    {
      std::cout << "At this day the event exists." << std::endl;
    }
    else
    {
      std::cout << "The event does not exist at this day." << std::endl;
    }
    break;
  }
  case '4': {
    ShowAllEvents();
    break;
  }
  case '5': {
    if (boughtTickets.size() == 0)
    {
      std::cout << "No tickets have been ordered yet." << std::endl;
      return;
    }
    std::cout << "The following tickets have been ordered:" << std::endl;
    for (size_t i = 0; i < boughtTickets.size(); i++)
    {
      std::cout << "Ticket " << i + 1 << ":" << std::endl;
      ShowTickets();
      std::cout << std::endl;
    }
    break;
  }
  case '6': {
    std::cout << "Enter id: ";
    std::cin >> id;
    DeleteTicket(id);
    break;
  }
  default:
    std::cout << "Action not found." << std::endl;
    std::cout << "Enter to continue..." << std::endl;
    std::cin.ignore(10, '\n');
    std::cin.get();
    break;
  }
}

void Customer::ShowTickets()
{
  for (size_t i = 0; i < boughtTickets.size(); i++)
  {
    boughtTickets[i].ShowTicket();
    std::cout << "----------" << std::endl;
  }
}

void Customer::ShowAllEvents()
{
  for (size_t i = 0; i < EventStore::events.size(); i++)
  {
    EventStore::events[i].ShowEvent();
    std::cout << "----------" << std::endl;
  }
}

void Customer::AddTicket(Ticket ticket)
{
  TicketStore::tickets.push_back(ticket);
}

void Customer::DeleteTicket(std::string ticketId)
{
  for (size_t i = 0; i < boughtTickets.size(); i++)
  {
    if (boughtTickets[i].getId() == ticketId)
    {
      boughtTickets.erase(boughtTickets.begin() + i);
      break;
    }
  }
}

void Customer::FindEventByDate(std::string date)
{
  for (size_t i = 0; i < EventStore::events.size(); i++)
  {
    if (EventStore::events[i].date == date)
    {
      EventStore::events[i].ShowEvent();
      break;
    }
  }
}

void Customer::FindEventByName(std::string name)
{
  for (size_t i = 0; i < EventStore::events.size(); i++)
  {
    if (EventStore::events[i].name == name)
    {
      EventStore::events[i].ShowEvent();
      break;
    }
  }
}
