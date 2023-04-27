#include "../Stores/UserStore.h"

UserStore::UserStore()
{
  this->users = {};
};

int UserStore::GetSize()
{
  return this->users.size();
}

void UserStore::Add(User *user)
{
  this->users.push_back(user);
}

void UserStore::Delete(size_t index)
{
  this->users.erase(this->users.begin() + index);
}

void UserStore::DeleteAll()
{
  this->users.clear();
}

void UserStore::DeleteAllCustomers()
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->users[index]->GetRole() == "customer")
    {
      this->Delete(index);
      break;
    }
  }
}

void UserStore::DeleteById(std::string id)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->users[index]->GetId() == id)
    {
      this->Delete(index);
      break;
    }
  }
}

bool UserStore::ExistsById(std::string id)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->users[index]->GetId() == id)
    {
      return true;
    }
  }

  return false;
}

User *UserStore::Get(size_t index)
{
  return this->users[index];
}

User *UserStore::FindById(std::string id)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->users[index]->GetId() == id)
    {
      return this->users[index];
    }
  }

  return nullptr;
}

User *UserStore::FindByLogin(std::string login)
{
  for (size_t index = 0; index < this->GetSize(); index++)
  {
    if (this->users[index]->GetLogin() == login)
    {
      return this->users[index];
    }
  }

  return nullptr;
}
