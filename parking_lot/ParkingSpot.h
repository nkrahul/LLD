#pragma once

#include <memory>
#include "Vehicle.h"

enum class SpotType {
	SMALL,
	COMPACT,
	LARGE,
	SIZE // To get enum size
};

class ParkingSpot {

private:
	int m_spotID;
	bool m_occupied;
	SpotType m_spotType;
	std::string m_numberPlate;

public:
	ParkingSpot(int id, SpotType type, bool isOccupied = false, std::string numberPlate);

	int getSpotID() const;

	bool isOccupied() const;

	void setOccupied(bool occupied);

	std::shared_ptr<Vehicle> getVehicle() const;

	void setVehicle(std::shared_ptr<Vehicle> vehiclePtr);

	SpotType ParkingSpot::getSpotType() const;

	void setSpotType(SpotType type);
};
