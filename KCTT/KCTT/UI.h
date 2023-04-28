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

  static void PrintUsersTableTitle();
  static void PrintEventsTableTitle();
  static void PrintTicketsTableTitle();

  static void PrintRow();
  static void PrintUserTableRow(User *user);
  static void PrintEventTableRow(Event *event);
  static void PrintTicketTableRow(Ticket *ticket);

  static void EnterString(std::string title, std::string *string);

  static void SetWindowSize(int width, int height);
  static void DisableWindowScrollbar();
};