#pragma once

#include <string>
#include "Event.h"

class Ticket
{
private:
	std::string id;
	std::string Event;
	std::string Customer;
public:
	Ticket(std::string row, std::string place, bool isBooked);
	void getCustomer();
	void setCustomer();
	string getEvent();
	void setEvent();
	string getId();
};