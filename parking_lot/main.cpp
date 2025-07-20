#include<iostream>
#include<memory>
#include "ParkingLot.h"
#include "Vehicle.h"

int main() {
   ParkingLot& parkingLot = ParkingLot::getInstance();
   auto strategy = std::make_shared<HourlyFeeStrategy>(); 
   parkingLot.setFeeStrategy(strategy);

   std::map<Ticket, std::shared_ptr<Vehicle>> ticket_map;

   auto car = std::make_shared<Vehicle>("ABC123", VehicleType::CAR);
   auto bike = std::make_shared<Vehicle>("XYZ789", VehicleType::BIKE);
   auto truck = std::make_shared<Vehicle>("TRK456", VehicleType::TRUCK);

   auto t1 = parkingLot.parkVehicle(car);
   auto t2 = parkingLot.parkVehicle(bike);
   auto t3 = parkingLot.parkVehicle(truck);
   

   parkingLot.displayParkingLotStatus();

   parkingLot.unparkVehicle(t1.getTicketID());
   parkingLot.unparkVehicle(t2.getTicketID());
   parkingLot.unparkVehicle(t3.getTicketID());

   parkingLot.displayParkingLotStatus();

   return 0;
}