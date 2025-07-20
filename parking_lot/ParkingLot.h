#pragma once

#include <vector>
#include <unordered_map>
#include "ParkingLevel.h"
#include "Ticket.h"
#include "FeeStrategy.h"
#include "HourlyFeeStrategy.h"
#include <memory>
#include <set>
#include <unordered_map>

class ParkingLot {

private:
	static int ticketCounter; // Static counter for ticket IDs
	std::unordered_map<int, ParkingLevel> parkingLevels;
	std::unordered_map<int, Ticket> activeTickets;
	std::shared_ptr<FeeStrategy> feeStrategy;
	std::unordered_map<int, std::unordered_set<int>> emptySlots; // Maps level ID to set of empty spot IDs 

	ParkingLot() {
		feeStrategy = std::make_unique<HourlyFeeStrategy>(); // Initialize with default fee strategy
	};
	~ParkingLot() = default; // Default destructor

	public:
	ParkingLot(const ParkingLot&) = delete; // Disable copy constructor
	ParkingLot& operator=(const ParkingLot&) = delete; // Disable assignment operator
	static ParkingLot& getInstance();

	bool addParkingLevel();
	bool removeParkingLevel(int level);
	bool parkVehicle(std::shared_ptr<Vehicle> vehicle);
	bool unparkVehicle(int ticketID);
	void setFeeStrategy(std::shared_ptr<FeeStrategy> strategy) {
		feeStrategy = std::move(strategy);
	}
	void displayParkingLotStatus() const;
	std::unordered_set<ParkingSpot, Compare::ParkingSpotCompare>& getEmptySlots() const;
};
