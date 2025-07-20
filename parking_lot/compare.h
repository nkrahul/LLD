#pragma once
#include "ParkingLevel.h"
#include "Ticket.h"

namespace Compare {
    struct ParkingSpotCompare {
        bool operator()(const ParkingSpot& lhs, const ParkingSpot& rhs) const {
            return lhs.getSpotID() <= rhs.getSpotID();
        }
    };
};