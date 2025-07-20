#include "HourlyFeeStrategy.h"
#include "Ticket.h"
#include <stdexcept>
#include <chrono>

float HourlyFeeStrategy::calculateFee(Ticket& ticket) {
	auto it = hourlyRates.find(ticket.getVehicle().getVehicleType());
	if (it == hourlyRates.end()) {
		throw std::runtime_error("Unknown vehicle type");
	}

	auto now = std::chrono::system_clock::now();
	auto& entryTime = ticket.getEntryTime();
	auto duration = now - entryTime;
	auto hours = std::chrono::duration_cast<std::chrono::hours>(duration).count();
	if (hours < 0) {
		throw std::runtime_error("Invalid time duration");
	}

	return it->second * static_cast<float>(hours);
}
