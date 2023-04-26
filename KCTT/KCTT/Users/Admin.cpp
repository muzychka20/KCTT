#include "./Admin.h"
#include "../Stores/EventStore.h"
#include "../Stores/TicketStore.h"
#include "../Stores/UserStore.h"
#include <string>

Admin::Admin(std::string name, std::string login, std::string password)
    : User(name, login, password)
{
  this->role = "Admin";
}

void Admin::DeleteEvent(std::string id)
{
  for (size_t i = 0; i < EventStore::events.size(); i++)
  {
    if (EventStore::events[i].GetId() == id)
    {
      EventStore::events.erase(EventStore::events.begin() + i);
      DeleteAllTicketsByEvent(EventStore::events[i].GetId());
      break;
    }
  }
}

void Admin::AddEvent(Event event)
{
  EventStore::events.push_back(event);
}

void Admin::EditEvent(std::string id)
{
  std::string field, newValue;
  std::cout << "Which field to edit?: ";
  std::cin >> field;
  std::cout << "New value: ";
  std::cin >> newValue;
  for (size_t i = 0; i < EventStore::events.size(); i++)
  {
    if (EventStore::events[i].GetId() == id)
    {
      if (field == "date")
      {
        EventStore::events[i].date = newValue;
      }
      else if (field == "start time")
      {
        EventStore::events[i].startTime = newValue;
      }
      else if (field == "end time")
      {
        EventStore::events[i].endTime = newValue;
      }
      else if (field == "name")
      {
        EventStore::events[i].name = newValue;
      }
      else if (field == "status")
      {
        EventStore::events[i].status = newValue;
      }
      break;
    }
  }
}

void Admin::DeleteAllTicketsByEvent(std::string eventId)
{
  for (size_t i = 0; i < TicketStore::tickets.size(); i++)
  {
    if (TicketStore::tickets[i].getEventId() == eventId)
    {
      TicketStore::tickets.erase(TicketStore::tickets.begin() + i);
      i--;
      break;
    }
  }
}

void Admin::DeleteAllTickets()
{
  TicketStore::tickets.clear();
}

void Admin::ShowTickets()
{
  if (TicketStore::tickets.empty())
  {
    std::cout << "Tickets is empty!" << std::endl;
  }
  else
  {
    for (size_t i = 0; i < TicketStore::tickets.size(); i++)
    {
      TicketStore::tickets[i].ShowTicket();
      std::cout << "----------" << std::endl;
    }
  }
}

void Admin::ShowAllEvents()
{
  if (EventStore::events.empty())
  {
    std::cout << "Events is empty!" << std::endl;
  }
  else
  {
    for (size_t i = 0; i < EventStore::events.size(); i++)
    {
      EventStore::events[i].ShowEvent();
      std::cout << "----------" << std::endl;
    }
  }
}

void Admin::FindEventByDate(std::string date)
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

void Admin::FindEventByName(std::string name)
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

void Admin::AddTicket(Ticket ticket)
{
  TicketStore::tickets.push_back(ticket);
}

void Admin::DeleteTicket(std::string ticketId)
{
  for (size_t i = 0; i < TicketStore::tickets.size(); i++)
  {
    if (TicketStore::tickets[i].getId() == ticketId)
    {
      TicketStore::tickets.erase(TicketStore::tickets.begin() + i);
      break;
    }
  }
}

void Admin::AddCustomer(Customer customer)
{
  UserStore::users.push_back(&customer);
}

void Admin::DeleteCustomer(std::string id)
{
  for (size_t i = 0; i < UserStore::users.size(); i++)
  {
    if (UserStore::users.at(i)->GetId() == id)
    {

      for (size_t i = 0; i < TicketStore::tickets.size(); i++)
      {
        if (UserStore::users.at(i)->GetId() ==
            TicketStore::tickets[i].getCustomerId())
        {
          DeleteTicket(TicketStore::tickets[i].getId());
        }
      }
      UserStore::users.erase(UserStore::users.begin() + i);
      break;
    }
  }
}

void Admin::EditCustomer(std::string id)
{
  std::string newValue;
  std::cout << "New name: ";
  std::cin >> newValue;
  for (size_t i = 0; i < UserStore::users.size(); i++)
  {
    if (UserStore::users.at(i)->GetId() == id)
    {
      UserStore::users.at(i)->SetName(newValue);
      break;
    }
  }
}

void Admin::ShowUsers()
{
  for (size_t i = 0; i < UserStore::users.size(); i++)
  {
    std::cout << "-----" << std::endl;
  }
}

void Admin::PrintMenu(char *action)
{
  std::cout << "1. Add new customer account" << std::endl;
  std::cout << "2. Update customer account" << std::endl;
  std::cout << "3. Delete customer account" << std::endl;
  std::cout << "4. Add new event" << std::endl;
  std::cout << "5. Update event" << std::endl;
  std::cout << "6. Delete event" << std::endl;
  std::cout << "7. Add ticket to event" << std::endl;
  std::cout << "8. Delete ticket" << std::endl;
  std::cout << "9. Show tickets" << std::endl;
  std::cout << "[y] Show events" << std::endl;
  std::cout << "[u] Show users" << std::endl;
  std::cout << "[x] Delete all tickets" << std::endl;
  std::cin >> *action;
}

void Admin::ActivateMenu(char *action)
{
  switch (*action)
  {
  case '1': {
    std::string name, login, password;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter login: ";
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> password;
    UserStore::users.push_back(new Customer(name, login, password));
    break;
  }
  case '2': {
    std::string id;
    std::cout << "Enter id: ";
    std::cin >> id;
    EditCustomer(id);
    break;
  }
  case '3': {
    std::string id;
    std::cout << "Enter id: ";
    std::cin >> id;
    DeleteCustomer(id);
    std::cout << "Customer has been deleted" << std::endl;
    break;
  }
  case '4': {
    Event event;
    std::cout << "Enter name: ";
    std::cin >> event.name;
    std::cout << "Enter time of start: ";
    std::cin >> event.startTime;
    std::cout << "Enter time of end: ";
    std::cin >> event.endTime;
    std::cout << "Enter date: ";
    std::cin >> event.date;
    std::cout << "Enter status: ";
    std::cin >> event.status;
    EventStore::events.push_back(event);
    break;
  }
  case '5': {
    std::string id;
    std::cout << "Enter id: ";
    std::cin >> id;
    EditEvent(id);
    break;
  }
  case '6': {
    std::string id;
    std::cout << "Enter id: ";
    std::cin >> id;
    DeleteEvent(id);
    break;
  }
  case '7': {
    std::string row, name, place, CustomerId, EventId;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter row: ";
    std::cin >> row;
    std::cout << "Enter place: ";
    std::cin >> place;
    std::cout << "Enter customer id: ";
    std::cin >> CustomerId;
    std::cout << "Enter event id: ";
    std::cin >> EventId;
    Ticket ticket(row, place, false);
    ticket.setEventId(EventId);
    ticket.setCustomerId(CustomerId);
    TicketStore::tickets.push_back(ticket);
    break;
  }
  case '8': {
    std::string id;
    std::cout << "Enter id: ";
    std::cin >> id;
    DeleteTicket(id);
    break;
  }
  case '9': {
    ShowTickets();
    break;
  }
  case 'x': {
    DeleteAllTickets();
    std::cout << "All tickets have beeen deleted!" << std::endl;
    break;
  }
  case 'y': {
    ShowAllEvents();
    break;
  }
  case 'u': {
    ShowUsers();
    break;
  }
  }
  system("pause");
}
