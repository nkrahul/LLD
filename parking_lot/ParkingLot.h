#pragma once

#include <vector>
#include <unordered_map>
#include "ParkingLevel.h"
#include "Ticket.h"
#include "FeeStrategy.h"
#include "HourlyFeeStrategy.h"
#include <memory>
#include <queue>
#include <array>
#include <unordered_map>
#include "constants.h"

class ParkingLot {

private:
	using pq_decl = std::priority_queue<int, std::vector<int>, std::greater<int>>;
	static constexpr int NUM_TYPES = static_cast<int> (SpotType::SIZE);

	static constexpr int NUM_LEVELS {3};
	static int m_ticketCounter; // Static counter for ticket IDs
	std::array<ParkingLevel, NUM_LEVELS> m_levels;
	std::unordered_map<int, Ticket> m_activeTickets;
	std::shared_ptr<FeeStrategy> m_feeStrategy;
	std::array<std::array<pq_decl, NUM_TYPES>, CONSTANTS::NUM_LEVELS> m_emptySlots;
	// Maintain priority queue of empty spot id(s) corresponding to levels.
	ParkingLot(std::shared_ptr<FeeStrategy> = std::make_shared<HourlyFeeStrategy>());
	~ParkingLot() = default; // Default destructor
	pq_decl& getEmptySpots(int level, SpotType type);
	pq_decl& getEmptyVehicleSLots(int level, VehicleType type);

public:
	ParkingLot(const ParkingLot&) = delete; // Disable copy constructor
	ParkingLot& operator=(const ParkingLot&) = delete; // Disable assignment operator
	static ParkingLot& getInstance();

	Ticket parkVehicle(std::shared_ptr<Vehicle> vehicle);
	std::shared_ptr<Vehicle> unparkVehicle(int ticketID);
	void setFeeStrategy(std::shared_ptr<FeeStrategy> strategy) {
		if(strategy) {
			m_feeStrategy = strategy;
		}
	}
	void displayParkingLotStatus();
	std::shared_ptr<ParkingSpot> getEmptyParkingSpot() const;
};
