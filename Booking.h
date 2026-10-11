#ifndef BOOKING_H
#define BOOKING_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Booking
{
private:
	string mFlightTime;
	string mSeat;
	string mPassengerName;

public:
	Booking();
	Booking(string aFlightTime, string aSeat, string aPassengerName);

	void SetFlightTime(string aFlightTime);
	void SetSeat(string aSeat);
	void SetPassenger(string aPassengerName);

	string GetFlightTime();
	string GetSeat();
	string GetPassengerName();

	void Display();
};
