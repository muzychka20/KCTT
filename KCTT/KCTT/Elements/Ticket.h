#pragma once

#include "../Elements/Event.h"
#include <string>

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
  std::string getId();
  std::string getRow();
  std::string getPlace();
  std::string getEventId();
  std::string getCustomerId();
  bool IsBooked();
  void Booking();
  void Unbooking();
  void setCustomerId(std::string newCustomer);
  void setEventId(std::string newEvent);
  void ShowTicket();
};