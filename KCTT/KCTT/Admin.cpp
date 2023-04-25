#include <string>
#include "Admin.h"
using namespace std;

Admin::Admin(std::string name, std::string login, std::string password) : User(name, login, password)
{
}

void Admin::DeleteEvent(string id)
{
}

void Admin::AddEvent(Event event)
{
}

void Admin::EditEvent(string id)
{
}

void Admin::DeleteAllTicketsByEvent(string eventId)
{
}

void Admin::DeleteAllTickets()
{
}

void Admin::AddCustomer(Customer customer)
{
}

void Admin::DeleteCustomer(string id)
{
}

void Admin::EditCustomer(string id)
{
}

void Admin::PrintMenu(char *action)
{
}

void Admin::ActivateMenu(char *action)
{
}

void Admin::ShowTickets()
{
}

void Admin::ShowAllEvents()
{
}

void Admin::AddTicket(Ticket ticket)
{
}

void Admin::DeleteTicket(std::string ticketId)
{
}

void Admin::FindEventByDate(std::string date)
{
}

void Admin::FindEventByName(std::string name)
{
}
