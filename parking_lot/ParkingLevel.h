#pragma once

#include <unordered_map>
#include <stdexcept>
#include "ParkingSpot.h"
#include <vector>
#include "compare.h"
#include <array>

class ParkingLevel {
private:
	static constexpr int NUM_SPOTS {10};
	int m_level;
	std::array<ParkingSpot, NUM_SPOTS> m_spots; 

public:
	ParkingLevel(int lvl);
	int getLevel() const;
	ParkingSpot& getSpot(int id);
};
