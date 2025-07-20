#pragma once

#include <unordered_map>
#include <stdexcept>
#include "ParkingSpot.h"
#include <unordered_set>
#include "compare.h"

class ParkingLevel {
private:
	int level;
	std::unordered_set<ParkingSpot, Compare::ParkingSpotCompare> parkingSpots;

public:
	bool addParkingSpot(int id);
	bool removeParkingSpot(int id);
	ParkingLevel(int lvl);
	int getLevel() const;
	ParkingSpot& getSpot(int id);
};
