#include "../Elements/Ticket.h"
#include "../Elements/Event.h"
#include <string>

int tid = 0;

Ticket::Ticket(std::string row, std::string place, bool isBooked)
{
  tid++;
  this->row = row;
  this->place = place;
  this->isBooked = isBooked;
  this->id = "t" + std::to_string(tid);
}

std::string Ticket::getId()
{
  return this->id;
}

std::string Ticket::getRow()
{
  return this->row;
}

std::string Ticket::getPlace()
{
  return this->place;
}

std::string Ticket::getCustomerId()
{
  return this->Customer_Id;
}

std::string Ticket::getEventId()
{
  return this->Event_Id;
}

bool Ticket::IsBooked()
{
  //
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
  std::cout << "Ticket_Id\t" << this->id << std::endl;
  std::cout << "Event\t" << this->Event_Id << std::endl;
  std::cout << "Customer\t" << this->Customer_Id << std::endl;
}