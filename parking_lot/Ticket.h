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
	int m_level;
	int m_spotID;
	std::string m_numberPlate;

public:
    ~Ticket() = default;
	Ticket(const int level, const int spotID, const std::string& numberPlate);
	Ticket(const Ticket&);
	Time& getEntryTime() const;
	int getTicketID() const;
	int getLevelID() const;
	int getSpotID() const;
	std::shared_ptr<Vehicle> getVehicle() const;
	std::string getNumberPlate() const;
};
