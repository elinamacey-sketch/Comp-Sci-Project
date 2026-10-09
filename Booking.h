#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Booking
{
private:
	string mFlightTime;
	string mSeat;
	int mPassenger;

public:
	Booking();
	Booking(string aFlightTime, string aSeat, int aPassenger);

	void SetFlightTime(string aFlightTime);
	void SetSeat(string aSeat);
	void SetPassenger(int aPassenger);

	string GetFlightTime();
	string GetSeat();
	int GetPassenger();

	void Display();
};