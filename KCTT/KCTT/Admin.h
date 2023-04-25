#pragma once

#include <string>
#include "Event.h"
#include "Customer.h"
#include "User.h"
using namespace std;

class Admin : public User
{
public:
	Admin(string name, string login, string password);
	void DeleteEvent(string id);
	void AddEvent(Event event);
	void EditEvent(string id);
	void DeleteAllTicketsByEvent(string eventId);
	void DeleteAllTickets();
	void AddCustomer(Customer customer);
	void DeleteCustomer(string id);
	void EditCustomer(string id);
	void PrintMenu(char *action) override;
	void ActivateMenu(char *action) override;
	void ShowTickets() override;
	void ShowAllEvents() override;
	void AddTicket(Ticket ticket) override;
	void DeleteTicket(string ticketId) override;
	void FindEventByDate(string date) override;
	void FindEventByName(string name) override;
};

