#include "Ticket.h"
#include "Event.h"

int uuid = 0;

Ticket::Ticket(std::string row, std::string place, bool isBooked)
{
	this->row = row;
	this->place = place;
	this->isBooked = isBooked;
	uuid++;
	this->id = "t" + std::to_string(uuid);
}

string Ticket::getCustomerId()
{
	return this->Customer_Id;
}

void Ticket::setCustomerId(std::string newCustomer)
{
	this->Customer_Id = newCustomer;
}

string Ticket::getEventId()
{
	return this->Event_Id;
}

void Ticket::setEventId(std::string newEvent)
{
	this->Event_Id = newEvent;
}

string Ticket::getId()
{
	return this->id;
}

void Ticket::ShowTicket()
{
	cout << "Ticket_Id\t" << this->id << endl;
	cout << "Event\t" << this->Event_Id << endl;
	cout << "Customer\t" << this->Customer_Id << endl;
}