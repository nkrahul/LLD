#include<iostream>
#include "ParkingLot.h"
#include "Vehicle.h"


int main() {
    try {
        ParkingLot& parkingLot = ParkingLot::getInstance();

        // Add a parking level
        for(int i = 0; i < 2; i++) {
            parkingLot.addParkingLevel();
        }

        // Create a vehicle and park it
        auto vehicle = std::make_shared<Vehicle>(VehicleType::COMPACT);
        if (parkingLot.parkVehicle(vehicle)) {
            std::cout << "Vehicle parked successfully." << std::endl;
        } else {
            std::cout << "Failed to park vehicle." << std::endl;
        }

        // Display parking lot status
        parkingLot.displayParkingLotStatus();

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}