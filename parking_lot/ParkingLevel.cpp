#include "ParkingLevel.h"

int ParkingLevel::getLevel() const {
	return m_level;
}

ParkingSpot& ParkingLevel::getSpot(int id) {
	return m_spots[id];
}

int ParkingLevel::getNumSpots() const {
	return static_cast<int>(m_spots.size());
}