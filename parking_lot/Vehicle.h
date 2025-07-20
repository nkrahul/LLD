#pragma once
#include <string>
#include "VehicleType.h"

class Vehicle {

private:
	const std::string numberPlate;
	const VehicleType vehicleType;

public:
	Vehicle(const std::string& numberPlate, const VehicleType vehicleType);
	std::string& getNumberPlate() const;
	VehicleType getVehicleType() const;
};
