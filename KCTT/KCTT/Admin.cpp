#include <string>
#include "Admin.h"
#include "UserStore.h"
#include "EventStore.h"
#include "TicketStore.h"
using namespace std;

Admin::Admin(std::string name, std::string login, std::string password) : User(name, login, password)
{    
    this->role = "Admin";
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
    string field, newValue;
    cout << "Which field to edit?: ";
    cin >> field;
    cout << "New value: ";
    cin >> newValue;
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].getId() == id) {
            if (field == "date") {
                EventStore::events[i].date = newValue;
            }
            else if (field == "start time") {
                EventStore::events[i].startTime = newValue;
            }
            else if (field == "end time") {
                EventStore::events[i].endTime = newValue;
            }
            else if (field == "name") {
                EventStore::events[i].name = newValue;
            }
            else if (field == "status") {
                EventStore::events[i].status = newValue;
            }            
            break;
        }
    }
}

void Admin::DeleteAllTicketsByEvent(string eventId)
{
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        if (TicketStore::tickets[i].getEventId() == eventId) {
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
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        TicketStore::tickets[i].ShowTicket();
        cout << "----------" << endl;
    }
}

void Admin::ShowAllEvents()
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        EventStore::events[i].ShowEvent();
        cout << "----------" << endl;
    }
}

void Admin::FindEventByDate(std::string date)
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].date == date) {
            EventStore::events[i].ShowEvent();
            break;
        }
    }
}

void Admin::FindEventByName(std::string name)
{
    for (size_t i = 0; i < EventStore::events.size(); i++) {
        if (EventStore::events[i].name == name) {
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
    for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
        if (TicketStore::tickets[i].getId() == ticketId) {
            TicketStore::tickets.erase(TicketStore::tickets.begin() + i);
            break;
        }
    }
}


void Admin::AddCustomer(Customer customer)
{
    UserStore::users.push_back(&customer);
}

void Admin::DeleteCustomer(string id)
{
    for (size_t i = 0; i < UserStore::users.size(); i++) {
        if (UserStore::users.at(i)->GetId() == id) {
            
            for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
                if (UserStore::users.at(i)->GetId() == TicketStore::tickets[i].getCustomerId()){
                    DeleteTicket(TicketStore::tickets[i].getId());
                }
            }            
            UserStore::users.erase(UserStore::users.begin() + i);
            break;
        }
    }    
}

void Admin::EditCustomer(string id)
{
    string newValue;
    cout << "New name: ";
    cin >> newValue;
    for (size_t i = 0; i < UserStore::users.size(); i++) {
        if (UserStore::users.at(i)->GetId() == id) {
            UserStore::users.at(i)->SetName(newValue);
            break;
        }
    }
}

void Admin::PrintMenu(char* action)
{    
    cout << "1. Add new customer account" << endl;
    cout << "2. Update customer account" << endl;
    cout << "3. Delete customer account" << endl;
    cout << "4. Add new event" << endl;
    cout << "5. Update event" << endl;
    cout << "6. Delete event" << endl;
    cout << "7. Add ticket to event" << endl;    
    cout << "8. Delete ticket" << endl;
    cout << "9. Delete all tickets" << endl;
    cin >> *action;
}

void Admin::ActivateMenu(char* action)
{
    string name, login, password,role, id;    
    switch (*action)
    {
    case '1':
        // add new customer
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter login: ";
        cin >> login;
        cout << "Enter password: ";
        cin >> password;
        UserStore::users.push_back(new Customer(name, login, password));
        // id role ?
        break;
    case '2':
        cout << "Enter id: ";
        cin >> id;
        EditCustomer(id);
        break;
    case '3':
        cout << "Enter id: ";
        cin >> id;
        DeleteCustomer(id);
        cout << "Customer has been deleted" << endl;
        break;

    case '4':
        // add new event        
        break;

    case '5':
        cout << "Enter id: ";
        cin >> id;
        EditEvent(id);
        break;

    case '6':
        cout << "Enter id: ";
        cin >> id;
        DeleteEvent(id);
        break;

    case '7':
        // add ticket
        break;

    case '8':
        cout << "Enter id: ";
        cin >> id;
        DeleteTicket(id);
        break;

    case '9':
        DeleteAllTickets();
        cout << "All tickets have beeen deleted!" << endl;
        break;
    }
    system("pause");
}
