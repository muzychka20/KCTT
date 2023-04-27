#include "./UI.h"
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
  std::cout << event->GetId() << std::endl;
}

void UI::PrintTicketRow(Ticket *ticket)
{
  //std::cout << ticket->GetId() << std::endl;
  std::cout
      << "-------------------------------------------------------------------"
      << std::endl;
  std::cout << "Event name: " << ticket->GetEventId() << std::endl
            << "Ticket name: " << ticket->GetId() << std::endl
            << "Row: " << ticket->GetRow() << std::endl
            << "Place: " << ticket->GetPlace() << std::endl
            << "Is booked: " << ticket->IsBooked() << std::endl;
}

void UI::PrintUserRow(User *user)
{
  //std::cout << user->GetId() << std::endl;
  std::cout << "-------------------------------------------------------------------" << std::endl;
  std::cout << "Name: " << user->GetName() << std::endl
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
