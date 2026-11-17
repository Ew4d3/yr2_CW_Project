// Flight.h - a single flight's metadata (code, destination, duration).
#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    Flight();
    Flight(const std::string& code, const std::string& destination, int durationMins);

    const std::string& getCode() const;
    const std::string& getDestination() const;
    int getDuration() const;

private:
    std::string code_;
    std::string destination_;
    int durationMins_;
};

#endif
