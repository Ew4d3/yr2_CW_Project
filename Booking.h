// Booking.h - one line of bookings.txt.
#ifndef BOOKING_H
#define BOOKING_H

#include <string>

class Booking {
public:
    Booking(const std::string& passengerId, const std::string& flightCode,
            const std::string& date, const std::string& seatClass);

    const std::string& getPassengerId() const;
    const std::string& getFlightCode() const;
    const std::string& getDate() const;        // format YYYY-MM-DD
    const std::string& getSeatClass() const;

private:
    std::string passengerId_;
    std::string flightCode_;
    std::string date_;
    std::string seatClass_;
};

#endif
