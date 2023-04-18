#pragma once

#include <iostream>
using namespace std;

class Event {
private:
	int id;
public:
	string name;
	int startTime;
	int endTime;
	int date;
	int status;

	int getId();
};