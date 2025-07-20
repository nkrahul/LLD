#include "ParkingLot.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <memory>

int ParkingLot::m_ticketCounter = 1;

 ParkingLot::pq_decl& ParkingLot::getEmptySpots(int level, SpotType type) {
    if(level > CONSTANTS::NUM_LEVELS) {
        throw std::invalid_argument("Invalid Level");
    }

    if(type >SpotType::LARGE) {
        throw std::invalid_argument("Invalid spot type");
    }

    switch (type)
    {
    case SpotType::SMALL :
        return m_emptySlots[level][0];
    
    case SpotType::COMPACT :
        return m_emptySlots[level][1];
    
    case SpotType::LARGE :
        return m_emptySlots[level][2];
    }
    // Add a default return to avoid compiler warning
    throw std::invalid_argument("Invalid SpotType");
}

ParkingLot::pq_decl& ParkingLot::getEmptyVehicleSLots(int level, VehicleType type) {
    switch (type)
    {
    case VehicleType::BIKE :
        /* code */
        if(!getEmptySpots(level, SpotType::SMALL).empty()) {
            return getEmptySpots(level, SpotType::SMALL);
        }

    case VehicleType::CAR :
        if(!getEmptySpots(level, SpotType::COMPACT).empty()) {
            return getEmptySpots(level, SpotType::COMPACT);
        }

    default:
        if(!getEmptySpots(level, SpotType::LARGE).empty()) {
            return getEmptySpots(level, SpotType::LARGE);
         }

    std::stringstream msg {"No empty slots at level "};
    msg << level << std::endl;
    throw std::runtime_error(msg.str());
  }
}

ParkingLot::ParkingLot()
{
    m_feeStrategy = std::make_shared<HourlyFeeStrategy>();
    for (int i = 0; i < CONSTANTS::NUM_LEVELS; i++) {
        int j = 0;
        while (j++ < CONSTANTS::NUM_SMALL_SPOTS) {
            m_levels[i].getSpot(j).setSpotType(SpotType::SMALL);
            getEmptySpots(i, SpotType::SMALL).push(m_levels[i].getSpot(j).getSpotID());
        }
        while (j++ < CONSTANTS::NUM_COMPACT_SPOTS) {
            m_levels[i].getSpot(j).setSpotType(SpotType::COMPACT);
            getEmptySpots(i, SpotType::COMPACT).push(m_levels[i].getSpot(j).getSpotID());
        }
        while (j++ < CONSTANTS::NUM_LARGE_SPOTS) {
            m_levels[i].getSpot(j).setSpotType(SpotType::LARGE);
            getEmptySpots(i, SpotType::LARGE).push(m_levels[i].getSpot(j).getSpotID());
        }
    }
}

ParkingLot& ParkingLot::getInstance() {
    static ParkingLot parkingLot; // Guaranteed to be destroyed, instantiated on first use
    return parkingLot;
}

bool ParkingLot::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    for(int i = 0 ; i < NUM_LEVELS; i++) {
        if(m_emptySlots[i].empty()) {
            std::cout << "No empty parking spot at level " << i << std::endl;
            continue;
        }

        int emptySpotID = getEmptySpots(i, vehicle->getVehicleType())
        auto emptySlot = m_levels[i].getSpot(emptySpotID);

        if(emptySlot.isOccupied()) {
            std::stringstream msg;
            msg << "Failed Attempt to Park: Slot " << emptySpotID << " at level " << i << " as it is already occupied.";
            throw std::runtime_error(msg.str());
        }

        m_emptySlots[i].pop(); // remove from empty slot list
        emptySlot.setVehicle(vehicle);
        emptySlot.setOccupied(true);

        Ticket ticket(emptySlot.getSpotID(), vehicle);
        m_activeTickets.insert({ticket.getTicketID(), ticket});

        std::cout << "Vehicle parked successfully at level " << i << ", slot " << emptySpotID
                  << ". Ticket ID: " << ticket.getTicketID() << std::endl;
        
        return true;
    }
    return false;
}

bool ParkingLot::unparkVehicle(int ticketID) {
   auto it = m_activeTickets.find(ticketID);

   if(it == m_activeTickets.end()) {
        std::cerr << "Please provide a valid active Ticket.\n";
        return false;
   }

   auto& ticket = it->second;

}

void ParkingLot::displayParkingLotStatus() const {
    for (int i = 0; i < CONSTANTS::NUM_LEVELS; ++i) {
        std::cout << "Level " << i << ":\n";
        for (int j = 1; j <= m_levels[i].getNumSpots(); ++j) {
            auto& spot = m_levels[i].getSpot(j);
            std::cout << "  Spot " << j << " [";
            switch (spot.getSpotType()) {
                case SpotType::SMALL: std::cout << "Small"; break;
                case SpotType::COMPACT: std::cout << "Compact"; break;
                case SpotType::LARGE: std::cout << "Large"; break;
            }
            std::cout << "] - ";
            if (spot.isOccupied()) {
                std::cout << "Occupied";
            } else {
                std::cout << "Empty";
            }
            std::cout << std::endl;
        }
    }
}