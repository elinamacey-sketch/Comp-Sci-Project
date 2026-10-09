#include "Booking.h"

Booking::Booking()
{
}
Booking::Booking(string aFlightTime, string aSeat, string aPassengerName)
{
	mFlightTime = aFlightTime;
	mSeat = aSeat;
	mPassengerName = aPassengerName;
}

void Booking::SetFlightTime(string aFlightTime)
{
	mFlightTime = aFlightTime;
}
void Booking::SetSeat(string aSeat)
{
	mSeat = aSeat;
}
void Booking::SetPassenger(string aPassengerName)
{
	mPassengerName = aPassengerName;
}

string Booking::GetFlightTime()
{
	return mFlightTime;
}
string Booking::GetSeat()
{
	return mSeat;
}
string Booking::GetPassengerName()
{
	return mPassengerName;
}

void Booking::Display()
{
	cout << "----- Booking -----" << endl;
	cout << "Name: " << mPassengerName << endl;
	cout << "Flight Time: " << mFlightTime << endl;
	cout << "Seat: " << mSeat << endl;
}
