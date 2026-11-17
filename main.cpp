// main.cpp - flight itinerary generator.
// Usage: ./itinerary [bookings.txt flights.txt requests.txt]
#include <iostream>
#include <string>

#include "ItineraryGenerator.h"

//g++ -o main main.cpp Flight.cpp Booking.cpp ItineraryGenerator.cpp && ./main

using namespace std;

int main(int argc, char* argv[]) {
    string bookingsFile = "bookings.txt.txt";
    string flightsFile  = "flights.txt.txt";
    string requestsFile = "requests.txt.txt";
    if (argc == 4) {
        bookingsFile = argv[1];
        flightsFile  = argv[2];
        requestsFile = argv[3];
    }

    ItineraryGenerator generator;

    if (!generator.loadFlights(flightsFile)) {
        cerr << "Error: cannot open " << flightsFile << "\n";
        return 1;
    }
    if (!generator.loadBookings(bookingsFile)) {
        cerr << "Error: cannot open " << bookingsFile << "\n";
        return 1;
    }
    if (!generator.processRequests(requestsFile, cout)) {
        cerr << "Error: cannot open " << requestsFile << "\n";
        return 1;
    }
    return 0;
}
