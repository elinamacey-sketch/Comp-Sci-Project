#include<iostream>
#include<vector>
#include<string>
#include "Booking.h"
#include "Flight.h"

using namespace std;

void ClearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void DisplayMenu() {
	cout << "\n============================================\n";
	cout << "          Flight Booking System Menu         \n";
	cout << "===============================================\n";
	cout << "1. Display Available Flights & Seats\n";
	cout << "2. Book a Seat\n";
	cout << "3. View All Actives Bookings\n";
	cout << "4. Cancel a Booking\n";
	cout << "5. Exit\n";
	cout << "----------------------------------------------\n";
	cout << "Enter your choice (1-5): ";
}

int main()
{

	vector <Flight> flights;
	vector <Booking> bookings;

	flights.push_back(Flight("5:40 AM", 150)); 
	flights.push_back(Flight("6:30 PM", 170)); 
	flights.push_back(Flight("10:55 PM", 200)); 

		int choice = 0;
	bool running = true;

	while (running) {
		DisplayMenu();

		if (!(cin >> choice)) {
			cout << "\nInvalid input! Please enter a number through 1-5.\n";
				ClearInput();
			continue;
		}

		switch (choice) {
		case 1: {
			cout << "\n---Available Flights---\n";
			for (size_t i = 0; i < flights.size(); i++) {
				cout << "\nFlight #" << (i + 1);
				flights[i].displayFlight(true); 
			}
			break;
		}
		case 2: {
			cout << "\n---Book A Seat---\n";
			for (size_t i = 0; i < flights.size(); i++) {
				cout << i + 1 << ".Flight Time: " << flights[i].getFlightTime() << endl;
			}
			cout << "Select a flight number (1-" << flights.size() << "): ";
			int flightIndex;
			if (!(cin >> flightIndex) || flightIndex < 1 || flightIndex > static_cast<int>(flights.size())) {
				cout << "Invalid flight selection.\n";
				ClearInput();
				break;
			}
			flightIndex--;

			Flight& selectedFlight = flights[flightIndex];

			selectedFlight.displayAvailableSeats(); 
				cout << "Enter Seat Code (e.g., A1): ";
			string seatCode;
			cin >> seatCode;

			if (!(selectedFlight.isSeatAvailable(seatCode))){
				cout << "Error: Seat " << seatCode << " is not available.\n";
					break;
			}
			cout << "Enter Passenger Name: ";
				ClearInput();
				string PassengerName;
				getline(cin, PassengerName);

				selectedFlight.makeSeatUnavailable(seatCode); 
				Booking newBooking(selectedFlight.getFlightTime(), seatCode, PassengerName);
				bookings.push_back(newBooking);

			cout << "\nSuccess! Flight booked for " << PassengerName << ".\n";
			break;

		}
		case 3: {
			cout << "\n---Active Booking---\n";
			if (bookings.empty()) {
				cout << "No bookings made yet.\n";
			}
			else {
				for (size_t i = 0; i < bookings.size(); i++) {
					cout << "\nBooking #" << (i + 1) << endl;
					bookings[i].Display();
				}
			}
			break;
		}
		case 4: {
			cout << "\n---Cancel a Reservation---\n";
			if (bookings.empty()) {
				cout << "No active bookings to cancel.\n";
				break;
			}
			for (size_t i = 0; i < bookings.size(); i++) {
				cout << i + 1 << ". " << bookings[i].GetPassengerName()
					<< " | Flight: " << bookings[i].GetFlightTime()
					<< " | Seat: " << bookings[i].GetSeat() << endl; 
			}
			cout << "Select booking number to cancel: ";
			int CancelIndex;
			if (!(cin >> CancelIndex) || CancelIndex < 1 || CancelIndex > static_cast<int>(bookings.size())) {
				ClearInput();
				break;
			}
			CancelIndex--;

			Booking cancelledBooking = bookings[CancelIndex];

			for (size_t i = 0; i < flights.size(); i++) {
				if (flights[i].getFlightTime() == cancelledBooking.GetFlightTime()) {
					flights[i].makeSeatAvailable(cancelledBooking.GetSeat());
						break;
				}
			}
			bookings.erase(bookings.begin() + CancelIndex);
			cout << "Booking successfully canceled.\n";
			break;
		}
		case 5: {
			cout << "\nExiting system. Thank you!\n";
			running = false;
			break;
		}
		default:
			cout << "\nInvalid selection. Please choose an option between 1 and 5.\n";
			break;
		}
	}

	system("pause");
	return 0;
}
