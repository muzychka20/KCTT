#include "../Elements/Event.h"
#include <string>

int eid = 0;

Event::Event(std::string name, std::string date, std::string startTime,
             std::string endTime)
{
  eid++;
  this->id = "e" + std::to_string(eid);
  this->name = name;
  this->date = date;
  this->startTime = startTime;
  this->endTime = endTime;
  this->status = "opened";
}

std::string Event::GetId()
{
  return this->id;
}

std::string Event::GetName()
{
  return this->name;
}

std::string Event::GetDate()
{
  return this->date;
}

std::string Event::GetStatus()
{
  return this->status;
}

std::string Event::GetStartTime()
{
  return this->startTime;
}

std::string Event::GetEndTime()
{
  return this->endTime;
}

void Event::SetName(std::string newName)
{
  this->name = newName;
}

void Event::SetDate(std::string newDate)
{
  this->date = newDate;
}

void Event::SetStatus(std::string newStatus)
{
  this->status = newStatus;
}

void Event::SetStartTime(std::string newStartTime)
{
  this->startTime = newStartTime;
}

void Event::SetEndTime(std::string newEndTime)
{
  this->endTime = newEndTime;
}
