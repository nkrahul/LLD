#pragma once
#include <string>
#include <chrono>
#include "Vehicle.h"
#include "ParkingSpot.h"

using Time = std::chrono::system_clock::time_point;

class Ticket {
private:
	static int m_ticketCounter; // Static counter for ticket IDs
	int m_ticketID;
	Time m_entryTime;
	int m_spotID;
	std::shared_ptr<Vehicle> m_vehicle;

public:
    ~Ticket() = default;
	Ticket(int spotID, std::shared_ptr<Vehicle>);
	Ticket(const Ticket&);
	Time& getEntryTime() const;
	int getTicketID() const;
	std::shared_ptr<ParkingSpot> getSpot();
	std::shared_ptr<Vehicle> getVehicle() const;
};
