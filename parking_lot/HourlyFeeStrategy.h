#pragma once
#include <map>
#include "FeeStrategy.h"
#include "VehicleType.h"

class HourlyFeeStrategy : public FeeStrategy {
private:
	std::map<VehicleType, float> hourlyRates = {
		{VehicleType::CAR, 20.0f},
		{VehicleType::BIKE, 10.0f},
		{VehicleType::TRUCK, 30.0f},
		{VehicleType::BUS, 40.0f},
		{VehicleType::SUV, 22.0f}
	};
	
public:
	float calculateFee(Ticket& ticket) override;
	~HourlyFeeStrategy() override = default;
};
