#include <iostream>
#include "./User.h"
#include "./Admin.h"
#include "./Customer.h"
#include "./UserStore.h"

using namespace std;

int main() {
  User *user = NULL;
  char user_action;

  // Setup admins
  UserStore::users.push_back(new Admin("Kyrylo Muzychka", "kyrylo", "1"));
  UserStore::users.push_back(new Admin("Dmitry Tavern", "dmitry", "2"));
  UserStore::users.push_back(new Admin("Den Strateg", "den", "3"));
  UserStore::users.push_back(new Admin("Podion Boz", "rodion", "4"));
  UserStore::users.push_back(new Admin("Olga Kostrenko ", "olga", "5"));

  // Setup customers
  UserStore::users.push_back(new Customer("Customer #1", "custom1", "1"));
  UserStore::users.push_back(new Customer("Customer #2", "custom2", "1"));
  UserStore::users.push_back(new Customer("Customer #3", "custom3", "1"));

  // Authorize the user
  do {
    std::string username;
    std::cout << "Enter login: ";
    std::cin >> username;

    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    for (size_t i = 0; i < UserStore::users.size(); i++) {
      if (UserStore::users[i]->GetLogin() == username) {
        if (UserStore::users[i]->GetPassword() == password) {
          user = UserStore::users[i];
          break;
        }
      }
    }

    if (user == NULL) {
      std::cout << "Login or password is invalid." << std::endl;
    }
  } while (user == NULL);

  // Call the user menu
  do {
    system("cls");
    user->PrintMenu(&user_action);
    system("cls");
    user->ActivateMenu(&user_action);
    if (user_action == 'e')
      break;
  } while (true);
}
