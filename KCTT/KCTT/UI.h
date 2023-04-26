#pragma once
#include <iostream>
#include <vector>

class UI
{
public:
  static void PrintTitle(std::string title);
  static void PrintSimpleMenu(std::vector<std::string> items);
  static void EnterString(std::string title, std::string *string);
};