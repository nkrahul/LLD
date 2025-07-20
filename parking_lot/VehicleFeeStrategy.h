#pragma once
#include "FeeStrategy.h"
#include "VehicleType.h"
#include <map>

class VehicleFeeStrategy : public FeeStrategy {
private:
	std::map<VehicleType, float> vehicleRates = {
		{ VehicleType::COMPACT, 10.0f },
		{ VehicleType::TWO_WHEELER, 5.0f },
		{ VehicleType::LARGE, 15.0f }
	};

public:
	float calculateFee(Ticket& ticket) override;
};
