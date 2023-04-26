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
  void Add(Ticket ticket);
  void Delete(size_t index);
  void DeleteAll();
  void DeleteById(std::string id);
  void DeleteByRow(std::string row);
  void DeleteByPlace(std::string place);
  void DeleteByCustomerId(std::string customerId);
  Ticket *Get(size_t index);
  Ticket *FindById(std::string id);
  std::vector<Ticket> FindByRow(std::string row);
  std::vector<Ticket> FindByPlace(std::string place);
  std::vector<Ticket> FindByEventId(std::string eventId);
  std::vector<Ticket> FindByCustomerId(std::string customerId);
  std::vector<Ticket> Filter(TicketStoreFilter filter);

private:
  std::vector<Ticket> ticket;
};
