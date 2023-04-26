#include "../Stores/EventStore.h"

EventStore::EventStore()
{
  this->events = {};
};

int EventStore::GetSize()
{
  return this->events.size();
}

void EventStore::Add(Event event)
{
  this->events.push_back(event);
}

void EventStore::Delete(size_t index)
{
  this->events.erase(this->events.begin() + index);
}

void EventStore::DeleteAll()
{
  this->events.clear();
}

void EventStore::DeleteById(std::string id)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->events[index].GetId() == id)
    {
      this->Delete(index);
      break;
    }
  }
}

void EventStore::DeleteByName(std::string name)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->events[index].GetName() == name)
    {
      this->Delete(index);
      break;
    }
  }
}

void EventStore::DeleteByDate(std::string date)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->events[index].GetDate() == date)
    {
      this->Delete(index);
      break;
    }
  }
}

Event *EventStore::Get(size_t index)
{
  return &this->events[index];
}

std::vector<Event> EventStore::FindByName(std::string name)
{
  std::vector<Event> found;

  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->events[index].GetName() == name)
    {
      found.push_back(this->events[index]);
    }
  }

  return found;
}

std::vector<Event> EventStore::FindByDate(std::string date)
{
  std::vector<Event> found;

  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->events[index].GetDate() == date)
    {
      found.push_back(this->events[index]);
    }
  }

  return found;
}
