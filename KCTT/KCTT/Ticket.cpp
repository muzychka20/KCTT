#include "Ticket.h"
#include "Event.h"
#include <string>

int tid = 0;

Ticket::Ticket(std::string row, std::string place, bool isBooked)
{
	this->row = row;
	this->place = place;
	this->isBooked = isBooked;
	tid++;
	this->id = "t" + std::to_string(tid);
}

string Ticket::getId()
{
	return this->id;
}

string Ticket::getRow()
{
	return this->row;
}

string Ticket::getPlace()
{
	return this->place;
}

string Ticket::getCustomerId()
{
	return this->Customer_Id;
}

string Ticket::getEventId()
{
	return this->Event_Id;
}

bool Ticket::IsBooked()
{
	return this->isBooked;
}

void Ticket::Booking()
{
	this->isBooked = true;
}

void Ticket::Unbooking()
{
	this->isBooked = false;
}

void Ticket::setCustomerId(std::string newCustomer)
{
	this->Customer_Id = newCustomer;
}

void Ticket::setEventId(std::string newEvent)
{
	this->Event_Id = newEvent;
}

void Ticket::ShowTicket()
{
	cout << "Ticket_Id\t" << this->id << endl;
	cout << "Event\t" << this->Event_Id << endl;
	cout << "Customer\t" << this->Customer_Id << endl;
}