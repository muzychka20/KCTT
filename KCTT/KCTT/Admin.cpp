#include <string>
#include "Admin.h"
#include "UserStore.h"
#include "EventStore.h"
#include "TicketStore.h"
using namespace std;

Admin::Admin(std::string name, std::string login, std::string password) : User(name, login, password)
{
}

void Admin::DeleteEvent(string id)
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].getId() == id) {
            EventStore::events.erase(EventStore::events.begin()+i);
            DeleteAllTicketsByEvent(EventStore::events[i].getId());
            break;
        }
    }
}

void Admin::AddEvent(Event event)
{
	EventStore::events.push_back(event);
}

void Admin::EditEvent(string id)
{

}

void Admin::DeleteAllTicketsByEvent(string eventId)
{
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        if (TicketStore::tickets[i].getEvent() == eventId) {
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

void Admin::AddCustomer(Customer customer)
{
    //UserStore::users.push_back();
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
