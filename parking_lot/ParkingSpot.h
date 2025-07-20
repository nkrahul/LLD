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
	std::shared_ptr<Vehicle> m_vehicle;

public:
	ParkingSpot(int id, SpotType type, bool isOccupied = false, std::shared_ptr<Vehicle> vehiclePtr = nullptr);

	int getSpotID() const;

	bool isOccupied() const;

	void setOccupied(bool occupied);

	std::shared_ptr<Vehicle> getVehicle() const;

	void setVehicle(std::shared_ptr<Vehicle> vehiclePtr);

	SpotType getSpotType() const;

	void setSpotType(SpotType type);
};
