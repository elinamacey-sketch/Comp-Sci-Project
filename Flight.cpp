#include "Flight.h"

//Default Constructor
Flight::Flight()
{
	flightTime = "10:00 AM";
	capacity = 200;
	initializeSeats();
}

//Constructor w/parameters
Flight::Flight(string time, int cap)
{
	flightTime = time;
	capacity = cap;
	
	initializeSeats();
}

//Setter
void Flight::setFlightTime(string time)
{
	flightTime = time;
}

//Getters
string Flight::getFlightTime() const
{
	return flightTime;
}

int Flight::getCapacity() const
{
	return capacity;
}

vector<string> Flight::getAvailableSeats() const
{
	return availableSeats;
}

//Initialize seats
void Flight::initializeSeats()
{
	availableSeats.clear();
	unavailableSeats.clear();

	availableSeats.push_back("A1");
	availableSeats.push_back("A2");
}

//Display available seats
void Flight::displayAvailableSeats() const
{
	cout << "Available seats: ";
	if (availableSeats.empty())
	{
		cout << "None";
	}
	else
	{
		for (int i = 0; i < availableSeats.size(); i++)
		{
			cout << availableSeats[i] << " ";
		}
	}

	cout << endl;
}

//Check if seat is available
bool Flight::isSeatAvailable(string seat) const
{
	for (int i = 0; i < availableSeats.size(); i++)
	{
		if (availableSeats[i] == seat)
		{
			return true;
		}
	}

	return false;
}

//Change an available seat to unavailable
void Flight::makeSeatUnavailable(string seat)
{
	for (int i = 0; i < availableSeats.size(); i++)
	{
		if (availableSeats[i] == seat)
		{
			unavailableSeats.push_back(seat);
			availableSeats.erase(availableSeats.begin() + i);

			cout << seat << " is now unavailable." << endl;
			return;
		}
	}

	cout << seat << " is not available." << endl;
}

//Change unavailable seat to available
void Flight::makeSeatAvailable(string seat)
{
	for (int i = 0; i < unavailableSeats.size(); i++)
	{
		if (unavailableSeats[i] == seat)
		{
			availableSeats.push_back(seat);
			unavailableSeats.erase(unavailableSeats.begin() + i);

			cout << seat << " is now available." << endl;
			return;
		}
	}

	cout << seat << " was not found in unavailable seats." << endl;
}

//Display flight info
void Flight::displayFlight(bool showUnavailable) const
{
	cout << "\nFlight Information" << endl;
	cout << "Flight time: " << flightTime << endl;
	cout << "Capacity: " << capacity << endl;

	displayAvailableSeats();

	if (showUnavailable)
	{
		cout << "Unavailable seats: ";
		
		if (unavailableSeats.empty())
		{
			cout << "None";
		}
		else
		{
			for (int i = 0; i < unavailableSeats.size(); i++)
			{
				cout << unavailableSeats[i] << " ";
			}
		}
		
		cout << endl;
	}
}

//Check if flight if full 
bool Flight::isFull() const
{
	return availableSeats.size() >= capacity;
}
