#pragma once

#include <string>
#include "Event.h"

class Ticket
{
private:
	std::string row;
	std::string place;
	std::string id;
	std::string Event_Id;
	std::string Customer_Id;
public:
	Ticket(std::string row, std::string place, bool isBooked);
	string getCustomerId();
	void setCustomerId(std::string newCustomer);
	string getEventId();
	void setEventId(std::string newEvent);
	string getId();
	void ShowTicket();
};