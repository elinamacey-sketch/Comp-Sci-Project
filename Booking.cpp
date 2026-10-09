#include "Booking.h"

Booking::Booking()
{
	mPassenger = 0;
}
Booking::Booking(string aFlightTime, string aSeat, int aPassenger)
{
	mFlightTime = aFlightTime;
	mSeat = aSeat;
	mPassenger = aPassenger;
}

void Booking::SetFlightTime(string aFlightTime)
{
	mFlightTime = aFlightTime;
}
void Booking::SetSeat(string aSeat)
{
	mSeat = aSeat;
}
void Booking::SetPassenger(int aPassenger)
{
	mPassenger = aPassenger;
}

string Booking::GetFlightTime()
{
	return mFlightTime;
}
string Booking::GetSeat()
{
	return mSeat;
}
int Booking::GetPassenger()
{
	return mPassenger;
}

void Booking::Display()
{
	cout << "----- Booking -----" << endl;
	cout << "Flight Time: " << mFlightTime << endl;
	cout << "Seat: " << mSeat << endl;
}