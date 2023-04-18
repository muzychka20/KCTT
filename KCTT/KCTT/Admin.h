#pragma once

#include <string>
#include "Event.h"
#include "Customer.h"
#include "User.h"
using namespace std;

class Admin : public User
{
public:
	Admin(string name, string password, string login);
	void DeleteEvent(string id);
	void AddEvent(Event event);
	void EditEvent(string id);
	void DeleteAllTicketsByEvent(string eventId);
	void DeleteAllTickets();
	void AddCustomer(Customer customer);
	void DeleteCustomer(string id);
	void EditCustomer(string id);
	void PrintMenu() override;
	void ActivateMenu() override;
	void ShowTickets() override;
	void ShowAllEvents() override;
	void AddTicket(Ticket ticket) override;
	void DeleteTicket(std::string ticketId) override;
	void FindEventByDate(std::string date) override;
	void FindEventByName(std::string name) override;
};

