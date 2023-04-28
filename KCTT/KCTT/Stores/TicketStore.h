#pragma once
#include "../Elements/Ticket.h"
#include <vector>

class TicketStore
{
  struct TicketStoreFilter
  {
    std::string row;
    std::string place;
    std::string eventId;
    std::string customerId;
  };

public:
  TicketStore();
  int GetSize();
  void Add(Ticket *ticket);
  void Delete(size_t index);
  void DeleteAll();
  void DeleteById(std::string id);
  void DeleteByEventId(std::string eventId);
  void DeleteByCustomerId(std::string customerId);
  bool ExistsById(std::string id);
  Ticket *Get(size_t index);
  Ticket *FindById(std::string id);
  std::vector<Ticket *> Filter(TicketStoreFilter filter);

private:
  std::vector<Ticket *> ticket;
};
