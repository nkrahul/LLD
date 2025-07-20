#include "ParkingLevel.h"

ParkingLevel::ParkingLevel(int lvl) : level(lvl) {}

bool ParkingLevel::addParkingSpot(int id) {
	ParkingSpot newSpot(id);
	auto result = parkingSpots.insert(newSpot);
	return result.second; // Returns true if the spot was added, false if it already exists
}

bool ParkingLevel::removeParkingSpot(int id) {
	ParkingSpot spotToRemove(id);
	auto it = parkingSpots.find(spotToRemove);
	if (it != parkingSpots.end()) {
		parkingSpots.erase(it);
		return true; // Spot was found and removed
	}
	return false; // Spot not found
}

ParkingSpot& ParkingLevel::getSpot(int id) {
	ParkingSpot spotToFind(id);
	auto it = parkingSpots.find(spotToFind);
	if (it != parkingSpots.end()) {
		return const_cast<ParkingSpot&>(*it); // Return a non-const reference to the found spot
	}
	throw std::runtime_error("Parking spot not found.");
}
