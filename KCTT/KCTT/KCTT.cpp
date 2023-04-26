#include "./Stores/GlobalStore.h"
#include "./Stores/UserStore.h"
#include "./UI.h"
#include "./Users/Admin.h"
#include "./Users/Customer.h"
#include "./Users/User.h"
#include <iostream>
#include <string>
#include <vector>

void setup();
void authorize();
void activate();
void select(char *select);

int main()
{
  setup();

  do
  {
    char selector;

    system("cls");

    select(&selector);

    system("cls");

    switch (selector)
    {
    case '1':
      authorize();
      activate();
      break;
    case 'e':
      exit(0);
      break;
    }
  } while (true);
}

void setup()
{
  UserStore::users.push_back(new Admin("Kyrylo Muzychka", "kyrylo", "1"));
  UserStore::users.push_back(new Admin("Dmitry Tavern", "dmitry", "2"));
  UserStore::users.push_back(new Admin("Den Strateg", "den", "3"));
  UserStore::users.push_back(new Admin("Podion Boz", "rodion", "4"));
  UserStore::users.push_back(new Admin("Olga Kostrenko ", "olga", "5"));

  UserStore::users.push_back(new Customer("Customer #1", "custom1", "1"));
  UserStore::users.push_back(new Customer("Customer #2", "custom2", "1"));
  UserStore::users.push_back(new Customer("Customer #3", "custom3", "1"));
}

void select(char *select)
{
  std::vector<std::string> boot_menu = {"[1] Authorize in the system",
                                        "[2] About developers",
                                        "[e] Exit from program"};

  UI::PrintTitle("Boot Menu");
  UI::PrintSimpleMenu(boot_menu);
  std::cin >> *select;
}

void authorize()
{
  UI::PrintTitle("Authorize Menu");

  for (int attempts = 1; attempts <= 3; attempts++)
  {
    std::string login;
    UI::EnterString("Enter login: ", &login);

    std::string password;
    UI::EnterString("Enter password: ", &password);

    std::cout << login;

    for (size_t i = 0; i < UserStore::users.size(); i++)
    {
      if (UserStore::users[i]->CompareLogin(login))
      {
        if (UserStore::users[i]->ComparePassword(password))
        {
          GlobalStore::SetAuthorizedUser(UserStore::users[i]);
          return;
        }
      }
    }

    std::cout << "Error: login or password is invalid. Available attempts: "
              << 3 - attempts << std::endl;
  }
}

void activate()
{
  if (GlobalStore::IsAuthorizedUser())
  {
    User *user = GlobalStore::GetAuthorizedUser();

    do
    {
      char action;

      system("cls");

      user->PrintMenu(&action);

      system("cls");

      user->ActivateMenu(&action);

      if (action == 'e')
      {
        break;
      }
    } while (true);
  }
}
