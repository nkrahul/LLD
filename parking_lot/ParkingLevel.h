#pragma once

#include <unordered_map>
#include <stdexcept>
#include "ParkingSpot.h"
#include <vector>
#include "compare.h"
#include <array>
#include "constants.h"

class ParkingLevel {
private:
	int m_level;
	std::array<ParkingSpot, CONSTANTS::NUM_SPOTS> m_spots; 
	ParkingLevel() = default;
	~ParkingLevel() = default;

public:
	ParkingLevel(int lvl);
	int getLevel() const;
	ParkingSpot& getSpot(int id);
	int getNumSpots() const;
};
