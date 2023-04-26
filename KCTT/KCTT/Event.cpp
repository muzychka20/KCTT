#include "Event.h"
#include <string>
using namespace std;

int uuid = 0;

Event::Event()
{
	uuid++;
	this->id = "t" + std::to_string(uuid);
}

string Event::getId() {
	return this->id;
}

void Event::ShowEvent() {
	cout << "Name: " << this->name << endl;
	cout << "Start: " << this->startTime << endl;
	cout << "End: " << this->endTime << endl;
	cout << "Date: " << this->date << endl;
	cout << "Status: " << this->status << endl;
}