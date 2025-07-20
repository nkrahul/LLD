#include "ParkingLot.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>

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

ParkingLot::ParkingLot(std::shared_ptr<FeeStrategy> feeStrategy)
    : m_levels{ParkingLevel(0), ParkingLevel(1), ParkingLevel(2)}
{
    m_feeStrategy = feeStrategy;
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

Ticket ParkingLot::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    for(int i = 0 ; i < NUM_LEVELS; i++) {
        if(m_emptySlots[i].empty()) {
            std::cout << "No empty parking spot at level " << i << std::endl;
            continue;
        }

        auto emptySlots = getEmptyVehicleSLots(i, vehicle->getVehicleType());

        if(emptySlots.empty()) {
            std::stringstream msg;
            msg << "Failed Attempt to Park at level " << i << " as it is already occupied.";
            throw std::runtime_error(msg.str());
        }
        int emptySlotID = emptySlots.top();
        emptySlots.pop();
        auto slot = m_levels[i].getSpot(emptySlotID);
        slot.setOccupied(true);
        slot.setVehicle(std::move(vehicle));

        Ticket ticket(i, slot.getSpotID(), vehicle->getNumberPlate());
        m_activeTickets.insert({ticket.getTicketID(), ticket});

        std::cout << "Vehicle number " << vehicle->getNumberPlate() << " parked successfully at level " << i << ", slot " << emptySlotID
                  << ". Ticket ID: " << ticket.getTicketID() << std::endl;
        
        return ticket;
    }
    return Ticket(-1, -1, "-1");
}

std::shared_ptr<Vehicle> ParkingLot::unparkVehicle(int ticketID) {
   auto it = m_activeTickets.find(ticketID);

   if(it == m_activeTickets.end()) {
        std::cerr << "Please provide a valid active Ticket.\n";
        return nullptr;
   }

   auto& ticket = it->second;
   auto slot = m_levels[ticket.getLevelID()].getSpot(ticket.getSpotID());
   getEmptyVehicleSLots(ticket.getLevelID(), slot.getVehicle()->getVehicleType()).push(ticket.getSpotID()); // slot made available
   float fee = m_feeStrategy->calculateFee(ticket);

   std::cout << "Vehicle with number " << slot.getVehicle()->getNumberPlate() << "unparked from level " <<
                ticket.getLevelID() << " From spot " << ticket.getSpotID() << ", with fee " << fee << std::endl; 
   m_activeTickets.erase(ticket.getTicketID());

   return slot.getVehicle();
}

void ParkingLot::displayParkingLotStatus() {
    for (int i = 0; i < CONSTANTS::NUM_LEVELS; ++i) {
        std::cout << "Level " << i << ":\n";
        
        for(int j = 0; j < m_levels[i].getNumSpots(); j++) {
            std::string none {"None"};
            auto& spot = m_levels[i].getSpot(j);
            std::cout << "++ spotID " << spot.getSpotID() << ", vehicle "
                      << (spot.isOccupied() ? spot.getVehicle()->getNumberPlate() : none) << std::endl;
        }
    }
}