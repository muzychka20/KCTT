#include "./UI.h"
#include "Stores/GlobalStore.h"
#include <iomanip>
#include <iostream>
#include <string>

void UI::PrintTitle(std::string title)
{
  std::cout << "| " << std::setw(66) << std::left << title << " |" << std::endl;
}

void UI::PrintSimpleMenu(std::vector<std::string> items)
{
  UI::PrintRow();

  for (int i = 0; i < items.size(); i++)
  {
    std::cout << "| " << std::setw(66) << std::left << items[i] << " |"
              << std::endl;
  }

  UI::PrintRow();
}

void UI::PrintUsersTableTitle()
{
  std::cout << "| ";
  std::cout << std::setw(6) << std::left << "Id";
  std::cout << std::setw(20) << std::left << "Login";
  std::cout << std::setw(22) << std::left << "Name";
  std::cout << std::setw(19) << std::left << "Role";
  std::cout << "|" << std::endl;
}

void UI::PrintEventsTableTitle()
{
  std::cout << "| ";
  std::cout << std::setw(6) << std::left << "Id";
  std::cout << std::setw(20) << std::left << "Name";
  std::cout << std::setw(9) << std::left << "Status";
  std::cout << std::setw(12) << std::left << "Date";
  std::cout << std::setw(10) << std::left << "Start";
  std::cout << std::setw(10) << std::left << "End";
  std::cout << "|" << std::endl;
}

void UI::PrintTicketsTableTitle()
{
  std::cout << "| ";
  std::cout << std::setw(6) << std::left << "Id";
  std::cout << std::setw(10) << std::left << "Row";
  std::cout << std::setw(10) << std::left << "Place";
  std::cout << std::setw(19) << std::left << "Event";
  std::cout << std::setw(22) << std::left << "Customer";
  std::cout << "|" << std::endl;
}

void UI::PrintRow()
{
  std::cout << "|-" << std::setfill('-') << std::setw(66) << "-"
            << "-|" << std::endl;
  std::cout << std::setfill(' ');
}

void UI::PrintUserTableRow(User *user)
{
  std::cout << "| ";
  std::cout << std::setw(6) << std::left << user->GetId();
  std::cout << std::setw(20) << std::left << user->GetLogin();
  std::cout << std::setw(22) << std::left << user->GetName();
  std::cout << std::setw(19) << std::left << user->GetRole();
  std::cout << "|" << std::endl;
}

void UI::PrintEventTableRow(Event *event)
{
  std::cout << "| ";
  std::cout << std::setw(6) << std::left << event->GetId();
  std::cout << std::setw(20) << std::left << event->GetName();
  std::cout << std::setw(9) << std::left << event->GetStatus();
  std::cout << std::setw(12) << std::left << event->GetDate();
  std::cout << std::setw(10) << std::left << event->GetStartTime();
  std::cout << std::setw(10) << std::left << event->GetEndTime();
  std::cout << "|" << std::endl;
}

void UI::PrintTicketTableRow(Ticket *ticket)
{
  std::string eventId = ticket->GetEventId();
  std::string customerId = ticket->GetCustomerId();
  std::string customerName = "(empty)";
  Event *event = GlobalStore::GetEventStore()->FindById(eventId);

  if (!customerId.empty())
  {
    customerName = GlobalStore::GetUserStore()->FindById(customerId)->GetName();
  }

  std::cout << "| ";
  std::cout << std::setw(6) << std::left << ticket->GetId();
  std::cout << std::setw(10) << std::left << ticket->GetRow();
  std::cout << std::setw(10) << std::left << ticket->GetPlace();
  std::cout << std::setw(19) << std::left << event->GetName();
  std::cout << std::setw(22) << std::left << customerName;
  std::cout << "|" << std::endl;
}

void UI::EnterString(std::string title, std::string *string)
{
  do
  {
    std::cout << title;
    std::cin >> *string;
  } while (string->length() == 0);
}
