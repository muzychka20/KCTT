#pragma once
#include <iostream>

class Event
{
private:
  std::string id;

public:
  Event();
  std::string name;
  std::string date;
  std::string startTime;
  std::string endTime;
  std::string status;

  std::string GetId();

  void ShowEvent();
};