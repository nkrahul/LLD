#include "Vehicle.h"

Vehicle::Vehicle(const std::string numberPlate, const VehicleType vehicleType)
	: m_numberPlate(numberPlate), m_vehicleType(vehicleType) {}

Vehicle::~Vehicle() {}

const std::string& Vehicle::getNumberPlate() const {
	return m_numberPlate;
}

const VehicleType Vehicle::getVehicleType() const {
	return m_vehicleType;
}
