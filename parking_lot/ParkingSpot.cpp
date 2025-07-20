#include "ParkingSpot.h"

ParkingSpot::ParkingSpot(int id, bool isOccupied, std::shared_ptr<Vehicle> vehiclePtr)
	: spotID(id), occupied(isOccupied), vehicle(vehiclePtr) {}

int ParkingSpot::getSpotID() const{
	return spotID;
}

bool ParkingSpot::isOccupied() const {
	return occupied;
}

void ParkingSpot::setOccupied(bool occupied) {
	occupied = occupied;
}

std::shared_ptr<Vehicle> ParkingSpot::getVehicle() const {
	return vehicle;
}
