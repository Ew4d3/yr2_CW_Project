// Flight.cpp
#include "Flight.h"

Flight::Flight() : code_(""), destination_(""), durationMins_(0) {}

Flight::Flight(const std::string& code, const std::string& destination, int durationMins)
    : code_(code), destination_(destination), durationMins_(durationMins) {}

const std::string& Flight::getCode() const { return code_; }
const std::string& Flight::getDestination() const { return destination_; }
int Flight::getDuration() const { return durationMins_; }
