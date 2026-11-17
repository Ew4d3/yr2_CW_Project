// ItineraryGenerator.h - loads flights/bookings and prints itineraries.
#ifndef ITINERARY_GENERATOR_H
#define ITINERARY_GENERATOR_H

#include <iosfwd>
#include <map>
#include <string>
#include <vector>

#include "Booking.h"
#include "Flight.h"

class ItineraryGenerator {
public:
    // Each loader returns false if the file could not be opened.
    bool loadFlights(const std::string& filename);
    bool loadBookings(const std::string& filename);

    // Reads requests (one per line: "<passenger_id> [date]") and writes
    // the matching itineraries to 'out'. Returns false if the file
    // could not be opened.
    bool processRequests(const std::string& filename, std::ostream& out) const;

private:
    // Prints the itinerary for one passenger. An empty 'date' means the
    // full itinerary; otherwise only that date is printed.
    void printItinerary(const std::string& passengerId, const std::string& date,
                        std::ostream& out) const;

    void printFlightsOnDate(const std::string& date,
                            const std::vector<Booking>& bookings,
                            std::ostream& out) const;

    // flight code -> flight details
    std::map<std::string, Flight> flights_;
    // passenger id -> date (sorted, since YYYY-MM-DD sorts correctly as text)
    //              -> bookings on that date, in file order
    std::map<std::string, std::map<std::string, std::vector<Booking> > > bookings_;
};

#endif
