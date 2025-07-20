#pragma once
#include <map>
#include "FeeStrategy.h"
#include "VehicleType.h"

class HourlyFeeStrategy : public FeeStrategy {
private:
	std::map<VehicleType, float> hourlyRates = {
		{ VehicleType::COMPACT, 10.0f },
		{ VehicleType::TWO_WHEELER, 5.0f },
		{ VehicleType::LARGE, 15.0f }
	};
	
public:
	float calculateFee(std::shared_ptr<Ticket> ticket) override;
	~HourlyFeeStrategy() override = default;
};
