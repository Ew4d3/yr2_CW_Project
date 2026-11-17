// Booking.cpp
#include "Booking.h"

Booking::Booking(const std::string& passengerId, const std::string& flightCode,
                 const std::string& date, const std::string& seatClass)
    : passengerId_(passengerId), flightCode_(flightCode),
      date_(date), seatClass_(seatClass) {}

const std::string& Booking::getPassengerId() const { return passengerId_; }
const std::string& Booking::getFlightCode() const { return flightCode_; }
const std::string& Booking::getDate() const { return date_; }
const std::string& Booking::getSeatClass() const { return seatClass_; }

