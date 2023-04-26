#include "./Stores/GlobalStore.h"
#include "./Stores/UserStore.h"
#include "./UI.h"
#include "./Users/Admin.h"
#include "./Users/Customer.h"
#include "./Users/User.h"
#include <iostream>
#include <string>
#include <vector>

void authorize();
void activate();
void select(char *select);

int main()
{
  GlobalStore::InitUsersStore();
  GlobalStore::InitEventStore();
  GlobalStore::InitTicketStore();

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
    User *user;

    std::string login;
    UI::EnterString("Enter login: ", &login);

    user = GlobalStore::GetUserStore()->FindByLogin(login);

    if (user == nullptr)
    {
      std::cout << "Error: A user with this login will not be found. Available "
                   "attempts: "
                << 3 - attempts << std::endl;
      continue;
    }

    std::string password;
    UI::EnterString("Enter password: ", &password);

    if (!user->ComparePassword(password))
    {

      std::cout << "Error: password is invalid. Available attempts: "
                << 3 - attempts << std::endl;
      continue;
    }

    GlobalStore::SetAuthorizedUser(user);
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
