// ItineraryGenerator.cpp
#include "ItineraryGenerator.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

bool ItineraryGenerator::loadFlights(const string& filename) {
    ifstream in(filename.c_str());
    if (!in) return false;

    string code, destination;
    int duration;
    while (in >> code >> destination >> duration) {
        flights_[code] = Flight(code, destination, duration);
    }
    return true;
}

bool ItineraryGenerator::loadBookings(const string& filename) {
    ifstream in(filename.c_str());
    if (!in) return false;

    string passenger, flightCode, date, seatClass;
    while (in >> passenger >> flightCode >> date >> seatClass) {
        bookings_[passenger][date].push_back(
            Booking(passenger, flightCode, date, seatClass));
    }
    return true;
}

bool ItineraryGenerator::processRequests(const string& filename, ostream& out) const {
    ifstream in(filename.c_str());
    if (!in) return false;

    string line;
    while (getline(in, line)) {
        istringstream iss(line);
        string passengerId, date;
        if (!(iss >> passengerId)) continue;   // skip blank lines
        iss >> date;                           // stays empty if no date given
        printItinerary(passengerId, date, out);
    }
    return true;
}

void ItineraryGenerator::printFlightsOnDate(const string& date,
                                            const vector<Booking>& bookings,
                                            ostream& out) const {
    out << "  Date " << date << ":\n";
    for (size_t i = 0; i < bookings.size(); ++i) {
        const Booking& b = bookings[i];
        map<string, Flight>::const_iterator f = flights_.find(b.getFlightCode());
        if (f != flights_.end()) {
            out << "    " << f->second.getCode() << " "
                << f->second.getDestination() << " ("
                << f->second.getDuration() << " mins): "
                << b.getSeatClass() << "\n";
        } else {
            // Not expected (inputs are well formed) but avoids a crash.
            out << "    " << b.getFlightCode() << " Unknown (0 mins): "
                << b.getSeatClass() << "\n";
        }
    }
    out << "  Total Flights: " << bookings.size() << "\n";
}

void ItineraryGenerator::printItinerary(const string& passengerId, const string& date,
                                        ostream& out) const {
    out << "Passenger ID: " << passengerId << "\n";

    static const vector<Booking> noBookings;
    map<string, map<string, vector<Booking> > >::const_iterator p =
        bookings_.find(passengerId);

    // Specific date requested: that date only, no overall total.
    if (!date.empty()) {
        const vector<Booking>* day = &noBookings;
        if (p != bookings_.end()) {
            map<string, vector<Booking> >::const_iterator d = p->second.find(date);
            if (d != p->second.end()) day = &d->second;
        }
        printFlightsOnDate(date, *day, out);
        return;
    }

    // Full itinerary.
    size_t overall = 0;
    if (p != bookings_.end()) {
        for (map<string, vector<Booking> >::const_iterator d = p->second.begin();
             d != p->second.end(); ++d) {
            printFlightsOnDate(d->first, d->second, out);
            overall += d->second.size();
        }
    }
    out << "  Overall Flights: " << overall << "\n";
}
