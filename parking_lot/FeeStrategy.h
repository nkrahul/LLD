#pragma once
#include "Ticket.h"

class FeeStrategy {
public:
	virtual float calculateFee(std::shared_ptr<Ticket> ticket) = 0;
	virtual ~FeeStrategy() = default;
};
