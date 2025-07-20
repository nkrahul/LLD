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

class ParkingLot {

private:
	static constexpr int NUM_LEVELS {3};
	static int m_ticketCounter; // Static counter for ticket IDs
	std::array<ParkingLevel, NUM_LEVELS> m_levels;
	std::unordered_map<int, Ticket> m_activeTickets;
	std::shared_ptr<FeeStrategy> m_feeStrategy;
	std::array<std::priority_queue<std::shared_ptr<ParkingSpot>,
									std::vector<std::shared_ptr<ParkingSpot>>,
									Compare::ParkingSpotCompare>, NUM_LEVELS> m_emptySlots;

	ParkingLot(std::shared_ptr<FeeStrategy> feeStrategy = std::make_shared<HourlyFeeStrategy>()) {
		m_feeStrategy = feeStrategy; // Initialize with default fee strategy
	};
	~ParkingLot() = default; // Default destructor

	public:
	ParkingLot(const ParkingLot&) = delete; // Disable copy constructor
	ParkingLot& operator=(const ParkingLot&) = delete; // Disable assignment operator
	static ParkingLot& getInstance();

	bool parkVehicle(std::shared_ptr<Vehicle> vehicle);
	bool unparkVehicle(int ticketID);
	void setFeeStrategy(std::shared_ptr<FeeStrategy> strategy) {
		if(strategy) {
			m_feeStrategy = strategy;
		}
	}
	void displayParkingLotStatus() const;
	std::shared_ptr<ParkingSpot> getEmptyParkingSpot() const;
};
