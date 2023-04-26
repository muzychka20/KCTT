#pragma once

#include <string>
#include "Event.h"

class Ticket
{
private:
	bool isBooked;
	std::string id;
	std::string row;
	std::string place;
	std::string Event_Id;
	std::string Customer_Id;
public:
	Ticket(std::string row, std::string place, bool isBooked);
	string getId();
	string getRow();
	string getPlace();
	string getEventId();
	string getCustomerId();
	bool IsBooked();
	void Booking();
	void Unbooking();
	void setCustomerId(std::string newCustomer);
	void setEventId(std::string newEvent);
	void ShowTicket();
};