#include "./Admin.h"
#include "../Stores/EventStore.h"
#include "../Stores/GlobalStore.h"
#include "../Stores/TicketStore.h"
#include "../Stores/UserStore.h"
#include "../UI.h"
#include "./Customer.h"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

Admin::Admin(std::string name, std::string login, std::string password)
    : User(name, login, password)
{
  this->role = "Admin";
}

void Admin::PrintMenu(char *action)
{
  std::vector<std::string> menu = {
      "[1] Print events",
      "[2] Add new event",
      "[3] Update event",
      "[4] Delete event",
      "------------------------------------------------------------------",
      "[5] Print tickets",
      "[6] Add new ticket",
      "[7] Update ticket",
      "[8] Delete ticket",
      "[9] Delete ticket by event",
      "[f] Cancel ticket",
      "------------------------------------------------------------------",
      "[a] Print all users",
      "[b] Add new customer account",
      "[c] Update customer account",
      "[d] Delete customer account",
      "------------------------------------------------------------------",
      "                       Danger zone                      ",
      "------------------------------------------------------------------",
      "[z] Clear all events",
      "[y] Clear all tickets",
      "[x] Clear all customers",
      "------------------------------------------------------------------",
      "[e] Logout",
  };

  UI::PrintRow();
  UI::PrintTitle("Control panel");
  UI::PrintRow();
  UI::PrintSimpleMenu(menu);
  std::cin >> *action;
}

void Admin::ActivateMenu(char *action)
{
  switch (*action)
  {
  case '1':
    this->ToPrintEvents();
    system("pause");
    break;

  case '2':
    this->ToAddEvent();
    system("pause");
    break;

  case '3':
    this->ToEditEvent();
    system("pause");
    break;

  case '4':
    this->ToDeleteEvent();
    system("pause");
    break;

  case '5':
    this->ToPrintTickets();
    system("pause");
    break;

  case '6':
    this->ToAddTicket();
    system("pause");
    break;

  case '7':
    this->ToEditTicket();
    system("pause");
    break;

  case '8':
    this->ToDeleteTicket();
    system("pause");
    break;

  case '9':
    this->ToDeleteTicketByEvent();
    system("pause");
    break;

  case 'f':
    this->ToCancelTicket();
    system("pause");
    break;

  case 'a':
    this->ToPrintCustomers();
    system("pause");
    break;

  case 'b':
    this->ToAddCustomer();
    system("pause");
    break;

  case 'c':
    this->ToEditCustomer();
    system("pause");
    break;

  case 'd':
    this->ToDeleteCustomer();
    system("pause");
    break;

  case 'z':
    this->ToClearEvents();
    system("pause");
    break;

  case 'y':
    this->ToClearTickets();
    system("pause");
    break;

  case 'x':
    this->ToClearCustomers();
    system("pause");
    break;
  }
}

/*-------------------------------------------------------------------
 |                            Event                                 |
 -------------------------------------------------------------------*/

void Admin::ToPrintEvents()
{
  UI::PrintRow();
  UI::PrintTitle("Events");
  UI::PrintRow();

  int length = GlobalStore::GetEventStore()->GetSize();

  for (size_t index = 0; index < length; index++)
  {
    Event *event = GlobalStore::GetEventStore()->Get(index);
    UI::PrintEventTableRow(event);
  }

  UI::PrintRow();
}

void Admin::ToAddEvent()
{
  std::string name, date, startTime, endTime;

  UI::PrintRow();
  UI::PrintTitle("Add new event action");
  UI::PrintRow();
  UI::EnterString("Enter name: ", &name);
  UI::EnterString("Enter date: ", &date);
  UI::EnterString("Enter start time: ", &startTime);
  UI::EnterString("Enter end time: ", &endTime);

  GlobalStore::GetEventStore()->Add(new Event(name, date, startTime, endTime));

  std::cout << "Event success added!" << std::endl;
}

void Admin::ToEditEvent()
{
  std::string field, newValue, id;

  UI::PrintRow();
  UI::PrintTitle("Edit event action\nField for edit: Date, StartTime, EndTime, "
                 "Name, Status");
  UI::PrintRow();

  UI::EnterString("Which event to edit?: ", &id);
  UI::EnterString("Which field to edit?: ", &field);
  UI::EnterString("New value: ", &newValue);

  for (size_t i = 0; i < GlobalStore::GetEventStore()->GetSize(); i++)
  {
    if (GlobalStore::GetEventStore()->Get(i)->GetId() == id)
    {
      if (field == "Date")
      {
        GlobalStore::GetEventStore()->Get(i)->SetDate(newValue);
      }
      else if (field == "StartTime")
      {
        GlobalStore::GetEventStore()->Get(i)->SetStartTime(newValue);
      }
      else if (field == "EndTime")
      {
        GlobalStore::GetEventStore()->Get(i)->SetEndTime(newValue);
      }
      else if (field == "Name")
      {
        GlobalStore::GetEventStore()->Get(i)->SetName(newValue);
      }
      else if (field == "Status")
      {
        GlobalStore::GetEventStore()->Get(i)->SetStatus(newValue);
      }
      break;
    }
  }
  std::cout << "Event success updated!" << std::endl;
}

void Admin::ToDeleteEvent()
{
  UI::PrintRow();
  UI::PrintTitle("Delete event action");
  UI::PrintRow();

  std::string id;

  do
  {
    UI::EnterString("Enter event id: ", &id);

    if (id == "-")
    {
      break;
    }

    if (GlobalStore::GetEventStore()->ExistsById(id))
    {
      GlobalStore::GetEventStore()->DeleteById(id);
      GlobalStore::GetTicketStore()->DeleteByEventId(id);
      std::cout << "Event success deleted!" << std::endl;
      break;
    }

    std::cout << "Event with id: " << id << " not found." << std::endl;
  } while (true);
}

/*-------------------------------------------------------------------
 |                           Ticket                                 |
 -------------------------------------------------------------------*/

void Admin::ToPrintTickets()
{
  UI::PrintRow();
  UI::PrintTitle("Tickets");
  UI::PrintRow();

  int length = GlobalStore::GetTicketStore()->GetSize();

  for (size_t index = 0; index < length; index++)
  {
    Ticket *ticket = GlobalStore::GetTicketStore()->Get(index);
    UI::PrintTicketTableRow(ticket);
  }

  UI::PrintRow();
}

void Admin::ToAddTicket()
{
  UI::PrintRow();
  UI::PrintTitle("Add new ticket action");
  UI::PrintRow();

  std::string row, name, place, customerId, eventId;

  do
  {
    UI::EnterString("Enter event id: : ", &eventId);

    if (eventId == "-")
    {
      break;
    }

    if (GlobalStore::GetEventStore()->ExistsById(eventId))
    {
      UI::EnterString("Enter ticket row: ", &row);
      UI::EnterString("Enter ticket place: ", &place);

      GlobalStore::GetTicketStore()->Add(new Ticket(eventId, row, place));

      std::cout << "Ticket success added!" << std::endl;
      break;
    }

    std::cout << "Event with id: " << eventId << " not found." << std::endl;
  } while (true);
}

void Admin::ToEditTicket()
{
  std::string ticketId, newCustomerId;

  UI::PrintRow();
  UI::PrintTitle("Edit ticket");
  UI::PrintRow();
  UI::EnterString("Which ticket to edit?: ", &ticketId);
  UI::EnterString("New customer for ticket: ", &newCustomerId);

  for (size_t i = 0; i < GlobalStore::GetTicketStore()->GetSize(); i++)
  {
    if (GlobalStore::GetTicketStore()->Get(i)->GetId() == ticketId)
    {
      GlobalStore::GetTicketStore()->Get(i)->Booking(newCustomerId);
      break;
    }
  }
  std::cout << "Ticket success updated!" << std::endl;
}

void Admin::ToDeleteTicket()
{
  UI::PrintRow();
  UI::PrintTitle("Delete ticket action");
  UI::PrintRow();

  std::string id;

  do
  {
    UI::EnterString("Enter ticket id: ", &id);

    if (id == "-")
    {
      break;
    }

    if (GlobalStore::GetTicketStore()->ExistsById(id))
    {
      GlobalStore::GetTicketStore()->DeleteById(id);
      std::cout << "Ticket success deleted!" << std::endl;
      break;
    }

    std::cout << "Ticket with id: " << id << " not found." << std::endl;
  } while (true);
}

void Admin::ToDeleteTicketByEvent()
{
  UI::PrintRow();
  UI::PrintTitle("Delete all event tickets action");
  UI::PrintRow();

  std::string eventId;

  do
  {
    UI::EnterString("Enter event id: ", &eventId);

    if (eventId.empty())
    {
      break;
    }

    if (GlobalStore::GetEventStore()->ExistsById(eventId))
    {
      GlobalStore::GetTicketStore()->DeleteByEventId(eventId);
      std::cout << "Tickets for event with id" << eventId << " success deleted!"
                << std::endl;
      break;
    }

    std::cout << "Event with id: " << eventId << " not found." << std::endl;
  } while (true);
}

void Admin::ToCancelTicket()
{
  std::string id;
  UI::EnterString("Enter id of ticket to unbooking: ", &id);
  if (GlobalStore::GetTicketStore()->ExistsById(id))
  {
    if (GlobalStore::GetTicketStore()->FindById(id)->IsBooked())
    {
      GlobalStore::GetTicketStore()->FindById(id)->Unbooking();
      std::cout << "Ticket is unbooked!" << std::endl;
    }
    else
    {
      std::cout << "This ticket is not booked!" << std::endl;
    }
  }
  else
  {
    std::cout << "Ticket not found!" << std::endl;
  }
}

/*-------------------------------------------------------------------
 |                            Customer                              |
 -------------------------------------------------------------------*/

void Admin::ToPrintCustomers()
{
  UI::PrintRow();
  UI::PrintTitle("Customers");
  UI::PrintRow();

  int length = GlobalStore::GetUserStore()->GetSize();

  for (size_t index = 0; index < length; index++)
  {
    User *user = GlobalStore::GetUserStore()->Get(index);
    UI::PrintUserTableRow(user);
  }

  UI::PrintRow();
}

void Admin::ToAddCustomer()
{
  UI::PrintRow();
  UI::PrintTitle("Add event customer action");
  UI::PrintRow();

  std::string name, login, password;

  UI::EnterString("Enter name: ", &name);
  UI::EnterString("Enter login: ", &login);
  UI::EnterString("Enter password: ", &password);

  GlobalStore::GetUserStore()->Add(new Customer(name, login, password));

  std::cout << "Customer success added!" << std::endl;
}

void Admin::ToEditCustomer()
{
  std::string field, newValue, id;

  UI::PrintRow();
  UI::PrintTitle("Edit customer action\nField for edit: Name, Login, Password");
  UI::PrintRow();

  UI::EnterString("Which cutomer to edit?: ", &id);
  UI::EnterString("Which field to edit?: ", &field);
  UI::EnterString("New value: ", &newValue);

  for (size_t i = 0; i < GlobalStore::GetUserStore()->GetSize(); i++)
  {
    if (GlobalStore::GetUserStore()->Get(i)->GetId() == id)
    {
      if (field == "Name")
      {
        GlobalStore::GetUserStore()->Get(i)->SetName(newValue);
      }
      else if (field == "Login")
      {
        GlobalStore::GetUserStore()->Get(i)->SetLogin(newValue);
      }
      else if (field == "Password")
      {
        GlobalStore::GetUserStore()->Get(i)->SetPassword(newValue);
      }
      break;
    }
  }
  std::cout << "Customer success updated!" << std::endl;
}

void Admin::ToDeleteCustomer()
{
  UI::PrintRow();
  UI::PrintTitle("Delete customer action");
  UI::PrintRow();

  std::string id;

  do
  {
    UI::EnterString("Enter customer id: ", &id);

    if (id == "-")
    {
      break;
    }

    if (GlobalStore::GetUserStore()->ExistsById(id))
    {
      if (GlobalStore::GetUserStore()->FindById(id)->GetRole() == "customer")
      {
        GlobalStore::GetUserStore()->DeleteById(id);
        std::cout << "Customer success deleted!" << std::endl;
        break;
      }

      std::cout << "User with id: " << id << " is not customer." << std::endl;
    }

    std::cout << "Customer with id: " << id << " not found." << std::endl;
  } while (true);

  std::cout << "Customer success deleted!" << std::endl;
}

/*-------------------------------------------------------------------
 |                          Danger zone                             |
 -------------------------------------------------------------------*/

void Admin::ToClearEvents()
{
  UI::PrintRow();
  UI::PrintTitle("DANGER: clear events action");
  UI::PrintRow();

  std::string answer;

  UI::EnterString("Do you really want to delete all the events? (Y/n)",
                  &answer);

  if (answer == "y" || answer == "Y")
  {
    GlobalStore::GetEventStore()->DeleteAll();
    GlobalStore::GetTicketStore()->DeleteAll();
    std::cout << "Event cleansed!" << std::endl;
  }
}

void Admin::ToClearTickets()
{
  UI::PrintRow();
  UI::PrintTitle("DANGER: clear ticket action");
  UI::PrintRow();

  std::string answer;

  UI::EnterString("Do you really want to delete all the tickets? (Y/n)",
                  &answer);

  if (answer == "y" || answer == "Y")
  {
    GlobalStore::GetTicketStore()->DeleteAll();
    std::cout << "Event cleansed!" << std::endl;
  }
}

void Admin::ToClearCustomers()
{
  UI::PrintRow();
  UI::PrintTitle("DANGER: clear customers action");
  UI::PrintRow();

  std::string answer;

  UI::EnterString("Do you really want to delete all the customers? (Y/n)",
                  &answer);

  if (answer == "y" || answer == "Y")
  {
    GlobalStore::GetUserStore()->DeleteAllCustomers();
    std::cout << "Customers cleansed!" << std::endl;
  }
}
