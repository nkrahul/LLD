#pragma once

#include <memory>
#include "Vehicle.h"

class ParkingSpot {

private:
	int spotID;
	bool occupied;
	std::shared_ptr<Vehicle> vehicle;

public:
	ParkingSpot(int id, bool isOccupied = false, std::shared_ptr<Vehicle> vehiclePtr = nullptr);

	int getSpotID() const;

	bool isOccupied() const;

	void setOccupied(bool occupied);

	std::shared_ptr<Vehicle> getVehicle() const;

	void setVehicle(std::shared_ptr<Vehicle> vehiclePtr) {
		vehicle = std::move(vehiclePtr);
	}

	bool operator==(const ParkingSpot& other) const {
		return spotID == other.spotID;
	}
};
