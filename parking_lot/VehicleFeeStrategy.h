#pragma once
#include "FeeStrategy.h"
#include "VehicleType.h"
#include <map>

class VehicleFeeStrategy : public FeeStrategy {
private:
	std::map<VehicleType, float> vehicleRates = {
		{VehicleType::CAR, 20.0f},
		{VehicleType::BIKE, 10.0f},
		{VehicleType::TRUCK, 30.0f},
		{VehicleType::BUS, 40.0f},
		{VehicleType::SUV, 22.0f}
	};

public:
	float calculateFee(std::shared_ptr<Ticket> ticket) override;
};
