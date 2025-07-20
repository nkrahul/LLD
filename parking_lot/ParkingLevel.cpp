#include "ParkingLevel.h"

ParkingLevel::ParkingLevel(int lvl) : m_level(lvl) {
}

int ParkingLevel::getLevel() const {
	return m_level;
}

ParkingSpot& ParkingLevel::getSpot(int id) {
	return m_spots[id];
}
