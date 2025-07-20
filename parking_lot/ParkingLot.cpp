#include "ParkingLot.h"
#include <stdexcept>
#include <iostream>

int ParkingLot::ticketCounter = 0;

ParkingLot& ParkingLot::getInstance() {
    static ParkingLot parkingLot; // Guaranteed to be destroyed, instantiated on first use
    return parkingLot;
}

bool ParkingLot::addParkingLevel() {
    ParkingLevel newLevel(static_cast<int>(parkingLevels.size())); // Create a new level with a unique ID
    auto result = parkingLevels.insert(newLevel);
    if(!result.second) {
        throw std::runtime_error("Parking level already exists.");
    }

    return result.second; // Returns true if the level was added, false if it already exists
}

bool ParkingLot::removeParkingLevel(int level) {
    ParkingLevel levelToRemove(level);
    auto it = parkingLevels.find(levelToRemove);
    if (it != parkingLevels.end()) {
        parkingLevels.erase(it);
        return true; // Level was found and removed
    }
    return false; // Level not found
}

bool ParkingLot::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    bool vehicleParked = false;

    for(auto& level: emptySlots) {
        if(level.second.empty()) {
            std::cout << "No empty slots available in level " << level.first << std::endl;
            continue; // Skip if there are no empty spots in this level
        }

        for(auto spotID: level.second) {
            try {
              auto& parkingSpot = parkingLevels[level.first].getSpot(spotID);
                if(!parkingSpot.isOccupied()) {
                    parkingSpot.setOccupied(true);
                    parkingSpot.setVehicle(vehicle);
                    std::cout << "Vehicle parked in level " << level.first
                              << ", spot ID: " << parkingSpot.getSpotID() << std::endl;
                    Ticket newTicket(parkingSpot);
                    activeTickets.insert({newTicket.getTicketID(), newTicket}); // Store the ticket in activeTickets
                    vehicleParked = true;
                    emptySlots[level.first].erase(spotID); // Remove the spot from empty slots
                }
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error accessing parking spot: " << e.what() << std::endl;
                continue; // Skip to the next spot if the current one is not found
            }
        }
    }
    
    return vehicleParked;
}

bool ParkingLot::unparkVehicle(int ticketID) {
    bool foundTicket = false;

    auto it = activeTickets.find(ticketID);
    if (it != activeTickets.end()) {
        foundTicket = true;
        Ticket& ticket = it->second;
        ParkingSpot& spot = ticket.getSpot();

        if (spot.isOccupied()) {
            Vehicle *vehicle = spot.getVehicle().get();
            float fee = feeStrategy->calculateFee(ticket); // Calculate the fee for the ticket
            std::cout << "Unparking vehicle with number plate: " << vehicle->getNumberPlate()
                      << ", Fee: " << fee << std::endl;

            spot.setOccupied(false);
            spot.setVehicle(nullptr); // Clear the vehicle from the spot

            // Add the spot back to empty slots
            emptySlots[spot.getSpotID()].insert(spot.getSpotID());
            activeTickets.erase(it); // Remove the ticket from active tickets
        } else {
            std::cerr << "Parking spot is already empty." << std::endl;
        }
    } else {
        std::cerr << "Ticket ID not found." << std::endl;
    }
    return foundTicket;
}