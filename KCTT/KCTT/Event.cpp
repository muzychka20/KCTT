#include "Event.h"
using namespace std;

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