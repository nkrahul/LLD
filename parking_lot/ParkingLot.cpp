#include "ParkingLot.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <memory>

int ParkingLot::m_ticketCounter = 1;

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
        int emptySpotID = m_emptySlots[i].top(); // get lowest id empty slot
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