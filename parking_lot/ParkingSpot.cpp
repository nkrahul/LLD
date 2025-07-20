#include "ParkingSpot.h"

ParkingSpot::ParkingSpot(int id, SpotType type, bool isOccupied, std::shared_ptr<Vehicle> vehiclePtr)
	: m_spotID(id), m_spotType(type), m_occupied(isOccupied), m_vehicle(vehiclePtr) {}

int ParkingSpot::getSpotID() const{
	return m_spotID;
}

bool ParkingSpot::isOccupied() const {
	return m_occupied;
}

void ParkingSpot::setOccupied(bool occupied) {
	m_occupied = occupied;
}

std::shared_ptr<Vehicle> ParkingSpot::getVehicle() const {
	return m_vehicle;
}

void ParkingSpot::setVehicle(std::shared_ptr<Vehicle> vehiclePtr) {
	m_vehicle = vehiclePtr;
}

SpotType ParkingSpot::getSpotType() const {
	return m_spotType;
}

void ParkingSpot::setSpotType(SpotType type) {
	m_spotType = type;
}