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
  std::string eventId;
  std::string customerId;

public:
  Ticket(std::string eventId, std::string row, std::string place);
  std::string GetId();
  std::string GetRow();
  std::string GetPlace();
  std::string GetEventId();
  std::string GetCustomerId();
  bool IsBooked();
  void Booking();
  void Unbooking();
  void SetCustomerId(std::string newCustomer);
};