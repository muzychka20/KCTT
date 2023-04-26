#include "../Elements/Event.h"
#include <string>

int eid = 0;

Event::Event()
{
  eid++;
  this->id = "t" + std::to_string(eid);
}

std::string Event::GetId()
{
  return this->id;
}

void Event::ShowEvent()
{
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Start: " << this->startTime << std::endl;
  std::cout << "End: " << this->endTime << std::endl;
  std::cout << "Date: " << this->date << std::endl;
  std::cout << "Status: " << this->status << std::endl;
}