#pragma once
#include <string>
#include <chrono>
#include "Vehicle.h"
#include "ParkingSpot.h"

using Time = std::chrono::system_clock::time_point;

class Ticket {
private:
	static int ticketCounter; // Static counter for ticket IDs
	int ticketID;
	Time entryTime;
	ParkingSpot& spot;

public:
    ~Ticket() = default;
	Ticket(ParkingSpot& spot);
	Ticket(const Ticket&);
	Time& getEntryTime() const;
	int getTicketID() const;
	ParkingSpot& getSpot() const;
};
