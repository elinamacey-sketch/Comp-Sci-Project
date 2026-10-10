#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight
{
private:
	string flightTime;
	int capacity;
	vector<string> availableSeats;
	vector<string> unavailableSeats;

public:
	//Constructors
	Flight();
	Flight(string time, int cap);

	//Setter
	void setFlightTime(string time);

	//Getters
	string getFlightTime() const;
	int getCapacity() const;
	vector<string> getAvailableSeats() const;

	//Seat Functions

	void initializeSeats();
	void displayAvailableSeats() const;
	bool isSeatAvailable(string seat) const;
	void makeSeatUnavailable(string seat);
	void makeSeatAvailable(string seat);

	//Display flight info
	void displayFlight(bool showUnavailable = false) const;

	//Check if flight is full
	bool isFull() const;
};

#endif
