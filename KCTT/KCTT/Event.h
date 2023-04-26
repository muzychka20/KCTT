#pragma once

#include <iostream>
using namespace std;

class Event {
private:
	string id;
public:
	Event();
	string name;
	string startTime;
	string endTime;
	string date;
	string status;

	string getId();

	void ShowEvent();
};