#pragma once
#include "Ticket.h"

class FeeStrategy {
public:
	virtual float calculateFee(Ticket& ticket) = 0;
	virtual ~FeeStrategy() = default;
};
