#include "Vehicle.h"

Vehicle::Vehicle(const std::string& numberPlate, const VehicleType vehicleType)
	: numberPlate(numberPlate), vehicleType(vehicleType) {}

Vehicle::~Vehicle() {}

std::string& Vehicle::getNumberPlate() const {
	return const_cast<std::string&>(numberPlate);
}

VehicleType Vehicle::getVehicleType() const {
	return vehicleType;
}
