#pragma once
#include "./Elements/Event.h"
#include "./Elements/Ticket.h"
#include "./Users/User.h"
#include <iostream>
#include <vector>

class UI
{
public:
  static void PrintTitle(std::string title);
  static void PrintSimpleMenu(std::vector<std::string> items);
  static void PrintEventRow(Event *event);
  static void PrintTicketRow(Ticket *ticket);
  static void PrintUserRow(User *user);
  static void EnterString(std::string title, std::string *string);
};