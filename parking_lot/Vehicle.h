#pragma once
#include <string>
#include "VehicleType.h"

class Vehicle {

private:
	const std::string m_numberPlate;
	const VehicleType m_vehicleType;

public:
	Vehicle(const std::string& numberPlate, const VehicleType vehicleType);
	~Vehicle() = default;
	const std::string& getNumberPlate() const;
	const VehicleType getVehicleType() const;
};
