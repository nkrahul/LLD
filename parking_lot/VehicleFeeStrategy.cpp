#include "VehicleFeeStrategy.h"
#include "Ticket.h"
#include <stdexcept>

float VehicleFeeStrategy::calculateFee(std::shared_ptr<Ticket> ticket) {
	auto it = vehicleRates.find(ticket->getVehicle()->getVehicleType());
	if (it == vehicleRates.end()) {
		throw std::runtime_error("Unknown vehicle type");
	}

	// For VehicleFeeStrategy, we assume a flat fee per vehicle type
	return it->second;
}
