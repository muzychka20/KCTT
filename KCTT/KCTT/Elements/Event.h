#pragma once
#include <iostream>
#include <string>

class Event
{
private:
  std::string id;
  std::string name;
  std::string date;
  std::string status;
  std::string startTime;
  std::string endTime;

public:
  Event(std::string name, std::string date, std::string startTime,
        std::string endTime);
  std::string GetId();
  std::string GetName();
  std::string GetDate();
  std::string GetStatus();
  std::string GetStartTime();
  std::string GetEndTime();
  void SetName(std::string name);
  void SetDate(std::string date);
  void SetStatus(std::string status);
  void SetStartTime(std::string endTime);
  void SetEndTime(std::string startTime);
};