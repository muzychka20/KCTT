#include "Customer.h"
#include "TicketStore.h"
#include "EventStore.h"
#include"Event.h"
#include"Ticket.h"
#include <iostream>
#include <stdio.h>


Customer::Customer(std::string name, std::string login, std::string password) : User(name, login, password)
{
    this->role = "Customer";
}

void Customer::PrintMenu(char *action)
{
    std::cout << "\t Welcome customer!" << endl;
    std::cout << "      Please select an action:" << endl;
    std::cout << "  1. Buy a ticket" << endl;
    std::cout << "  2. Find an event by name" << endl;
    std::cout << "  3. Find an event by date" << endl;
    std::cout << "  4. View all events " << endl;
    std::cout << "  5. View purchased tickets" << endl;
    std::cout << "  6. Cancel a ticket" << endl;
    std::cout << "  Enter your choice (1-6): ";
    std::cin >> *action;

}

void Customer::ActivateMenu(char *action)
{
    string eventName, eventDate, row, place, id;
    bool isBooked;
    int choose = 0;
    system("cls");
    switch (*action)
    {
    case '1': {
        ShowAllEvents();
        cout << "Which event would you like to attend. Enter the name of the event: ";
        cin >> eventName;
        FindEventByName(eventName);
    

        bool eventExists = false;
        for (size_t i = 0; i < EventStore::events.size(); ++i)
        {
            if (EventStore::events[i].name == eventName) {
                eventExists = true;
                break;
            }
        }

        if (eventExists) {

            cout << "The event exists.Do you want to buy a ticket?(1/0): ";
            cin >> choose;
            if (choose == 1) {
                int numTickets = 0;
                cout << "Choose the row: ";
                cin >> row;
                cout << "Choose the place: ";
                cin >> place;

                bool isBooked = false;
                cout << "Do you want to book this place? (1/0): ";
                cin >> isBooked;

                cout << "How many tickets do you want to buy? ";
                cin >> numTickets;
                for (int i = 0; i < TicketStore::tickets.size(); ++i) {
                    Ticket ticket(row, place, isBooked);
                    AddTicket(ticket);
                }
                
            };
            if (choose == 0) cout << "You don't want to buy a ticket.";
        }
        else {
            cout << "The event does not exist."<<endl;

        }
        break;
        
    }
    case '2': {  
        cout << "Which event would you like to find. Enter the name of the event: ";
        cin >> eventName;
        FindEventByName(eventName);

        bool eventExists = false;
        for (size_t i = 0; i < EventStore::events.size(); i++)
        {
            if (EventStore::events[i].name == eventName) {
                eventExists = true;
                break;
            }
        }
        if (eventExists) {
            cout << "The event exists." << endl;
        }
        else {
            cout << "The event does not exist." << endl;
        }
        break;
    }
    case '3': {
        cout << "When would you like to attend event. Enter the date of the event: ";
        cin >> eventDate;
        FindEventByDate(eventDate);

        bool eventExists = false;
        for (size_t i = 0; i < EventStore::events.size(); i++)
        {
            if (EventStore::events[i].date == eventDate) {
                eventExists = true;
                break;
            }
        }
        if (eventExists) {
            cout << "At this day the event exists." << endl;
        }
        else {
            cout << "The event does not exist at this day." << endl;
        }
        break;
    }
    case '4': {
        ShowAllEvents();
        break;
    }
    case '5': {
        if (TicketStore::tickets.size() == 0) {
            cout << "No tickets have been ordered yet." << endl;
            return;
        }
        cout << "The following tickets have been ordered:" << endl;
        for (size_t i = 0; i < TicketStore::tickets.size(); i++) {
            cout << "Ticket " << i + 1 << ":" << endl;
            ShowTickets();
            cout << endl;
        }
        break;
    }
    case '6': {
        cout << "Enter id: ";
        cin >> id;
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
    for (size_t i = 0; i < boughtTickets.size(); i++) {
        boughtTickets[i].ShowTicket();
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
