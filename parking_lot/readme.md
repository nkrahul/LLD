Requirements:

1. The ParkingLot can have multiple Levels and each Level can have multiples SLots.
2. Each Slot can accomodate Vehicle - two-wheeler, compact (car, SUV). or large (truck, bus).
3. Upon parking request by Vehicle, empty slot will be searched and Ticket will be given.
4. Upon unparking data from Ticket will be taken and Fee will be calculated using Fee Strategy

Non-functional Requirements:
Concurrency

Class Identification:

1. ParkingLot : Singleton
2. ParkingLevel : parking level with multiple slots
3. Slot to house vehicles.
4. Vehicle
5. Ticket: to keep track of parking info
6. FeeStrategy: Strategy pattern for fee calculation.
