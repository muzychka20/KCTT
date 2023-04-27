#include "../Elements/Ticket.h"
#include "../Elements/Event.h"
#include <string>

int tid = 0;

Ticket::Ticket(std::string eventId, std::string row, std::string place)
{
  tid++;
  this->id = "t" + std::to_string(tid);
  this->eventId = eventId;
  this->row = row;
  this->place = place;
  this->isBooked = false;
}

std::string Ticket::GetId()
{
  return this->id;
}

std::string Ticket::GetRow()
{
  return this->row;
}

std::string Ticket::GetPlace()
{
  return this->place;
}

std::string Ticket::GetCustomerId()
{
  return this->customerId;
}

std::string Ticket::GetEventId()
{
  return this->eventId;
}

bool Ticket::IsBooked()
{
  return this->isBooked;
}

void Ticket::Booking()
{
  this->isBooked = true;
  this->customerId = "";
}

void Ticket::Unbooking()
{
  this->isBooked = false;
}

void Ticket::SetCustomerId(std::string newCustomer)
{
  this->customerId = newCustomer;
}
