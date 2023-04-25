#pragma once

#include <iostream>
using namespace std;

class Event {
private:
	string id;
public:
	string name;
	int startTime;
	int endTime;
	int date;
	int status;

	string getId();
};