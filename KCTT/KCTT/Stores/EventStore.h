#pragma once
#include "../Elements/Event.h"
#include <vector>

class EventStore
{
public:
  EventStore();
  int GetSize();
  void Add(Event *event);
  void Delete(size_t index);
  void DeleteAll();
  void DeleteById(std::string id);
  void DeleteByName(std::string name);
  void DeleteByDate(std::string date);
  bool ExistsById(std::string id);
  Event *Get(size_t index);
  Event *FindById(std::string id);
  std::vector<Event *> FindByDate(std::string date);
  std::vector<Event *> FindByName(std::string name);

private:
  std::vector<Event *> events;
};
