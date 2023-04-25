#pragma once

#include <vector>
#include "User.h"
#include "Ticket.h"
using namespace std;


class Customer : public User
{
public:
	vector<Ticket> boughtTickets;
	Customer(std::string name, std::string login, std::string password);
	void PrintMenu(char *action) override;
	void ActivateMenu(char *action) override;
	void ShowTickets() override;
	void ShowAllEvents() override;
	void AddTicket(Ticket ticket) override;
	void DeleteTicket(std::string ticketId) override;
	void FindEventByDate(std::string date) override;
	void FindEventByName(std::string name) override;
};

