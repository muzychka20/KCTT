#include "Customer.h"
#include "TicketStore.h"
#include "EventStore.h"

Customer::Customer(std::string name, std::string login, std::string password) : User(name, login, password)
{
}

void Customer::PrintMenu(char *action)
{

}

void Customer::ActivateMenu(char *action)
{
}

void Customer::ShowTickets()
{
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        cout << TicketStore::tickets[i].ShowTicket() << endl;
        cout << "----------" << endl;
    }
}

void Customer::ShowAllEvents()
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        EventStore::events[i].ShowEvent();
        cout << "----------" << endl;
    }
}

void Customer::AddTicket(Ticket ticket)
{
	TicketStore::tickets.push_back(ticket);
}

void Customer::DeleteTicket(std::string ticketId)
{
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        if (TicketStore::tickets[i].getId() == ticketId) {
            TicketStore::tickets.erase(TicketStore::tickets.begin() + i);
            break;
        }
    }
}

void Customer::FindEventByDate(std::string date)
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].date == date) {
            EventStore::events[i].ShowEvent();
            break;
        }
    }
}

void Customer::FindEventByName(std::string name)
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].name == name) {
            EventStore::events[i].ShowEvent();
            break;
        }
    }
}
