#include "Ticket.h"
#include "Event.h"

int uuid = 0;

Ticket::Ticket(std::string row, std::string place, bool isBooked)
{
	uuid++;
	this->id = "t" + std::to_string(uuid);
}

string Ticket::getCustomer()
{
	return this->Customer;
}

void Ticket::setCustomer()
{
}

string Ticket::getEvent()
{
	return this->Event;
}

void Ticket::setEvent()
{
}

string Ticket::getId()
{
	return this->id;
}
