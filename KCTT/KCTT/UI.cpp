#include "./UI.h"
#include "Stores/GlobalStore.h"
#include <iomanip>
#include <iostream>

void UI::PrintTitle(std::string title)
{
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');

  std::cout << "| " << std::setw(64) << std::left << title << "|" << std::endl;

  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');
}

void UI::PrintSimpleMenu(std::vector<std::string> items)
{
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');

  for (int i = 0; i < items.size(); i++)
  {
    std::cout << "| " << std::setw(64) << std::left << items[i] << "|"
              << std::endl;
  }

  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');
}

void UI::PrintEventRow(Event *event)
{
  std::cout << "Hi";
  /*
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');

  std::cout << "Event name: " << event->GetName() << std::endl
            << "Event start: " << event->GetStartTime() << std::endl
            << "Event end: " << event->GetEndTime() << std::endl
            << "Event date: " << event->GetDate() << std::endl
            << "Event status: " << event->GetStatus() << std::endl;
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');
  */
}

void UI::PrintTicketRow(Ticket *ticket)
{
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');


  std::string id = ticket->GetEventId();
  std::cout << "Event name: " << GlobalStore::GetEventStore()->FindById(id)->GetName() << std::endl;

  if (ticket->GetCustomerId().empty())
    std::cout << "User: empty" << std::endl;
  else
    std::cout << "User: " << ticket->GetCustomerId() << std::endl;

    std::cout << "Row: " << ticket->GetRow() << std::endl
              << "Place: " << ticket->GetPlace() << std::endl
              << "Is booked: " << ticket->IsBooked() << std::endl;
  std::cout << std::setfill('-') << std::setw(67) << "-" << std::endl;
  std::cout << std::setfill(' ');
}

void UI::PrintUserRow(User *user)
{
  std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Login: " << user->GetLogin() << std::endl
              << "Name: " << user->GetName() << std::endl
              << "Role: " << user->GetRole() << std::endl;
}

void UI::EnterString(std::string title, std::string *string)
{
  do
  {
    std::cout << title;
    std::cin >> *string;
  } while (string->length() == 0);
}
