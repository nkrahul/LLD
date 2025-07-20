#pragma once
#include "ParkingLevel.h"

namespace Compare {
    struct ParkingSpotCompare {
        bool operator()(std::shared_ptr<ParkingSpot> lhs, std::shared_ptr<ParkingSpot> rhs) const {
            return lhs->getSpotID() <= rhs->getSpotID();
        }
    };
};