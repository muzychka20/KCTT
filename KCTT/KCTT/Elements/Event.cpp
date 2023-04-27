#include "../Elements/Event.h"
#include <string>

int eid = 0;

Event::Event(std::string name, std::string date, std::string startTime,
             std::string endTime)
{
  eid++;
  this->id = "t" + std::to_string(eid);
  this->startTime = startTime;
  this->endTime = endTime;
  this->date = date;
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

void Event::SetName(std::string name)
{
  this->name = name;
}

void Event::SetDate(std::string date)
{
  this->date = date;
}

void Event::SetStatus(std::string status)
{
  this->status = status;
}

void Event::SetStartTime(std::string endTime)
{
  this->endTime = endTime;
}

void Event::SetEndTime(std::string startTime)
{
  this->startTime = startTime;
}
