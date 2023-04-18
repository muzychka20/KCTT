#pragma once

#include <vector>
#include "User.h"
#include "Ticket.h"
using namespace std;


class Customer : public User
{
public:
	vector<Ticket> boughtTickets;
	Customer(string name, string password, string login);
	void PrintMenu() override;
	void ActivateMenu() override;
	void ShowTickets() override;
	void ShowAllEvents() override;
	void AddTicket(Ticket ticket) override;
	void DeleteTicket(std::string ticketId) override;
	void FindEventByDate(std::string date) override;
	void FindEventByName(std::string name) override;
};

