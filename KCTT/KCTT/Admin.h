#pragma once

#include <string>
#include "event.h"
#include "customer.h"
using namespace std;

class Admin
{
public:
	void DeleteEvent(string id);
	void AddEvent(event e);
	void EditEvent(string id);
	void DeleteAllTicketsByEvent(string eventId);
	void DeleteAllTickets();
	void AddCustomer(Customer customer);
	void DeleteCustomer(string id);
	void EditCustomer(string id);
};

