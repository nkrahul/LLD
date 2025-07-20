#include "Ticket.h"

int Ticket::ticketCounter = 0; // Initialize static counter

Ticket::Ticket(ParkingSpot& spot)
	: ticketID(++ticketCounter), spot(spot), entryTime(std::chrono::system_clock::now()) {
	// Constructor initializes the ticket with a unique ID and associates it with a parking spot
}

Ticket::Ticket(const Ticket& other)
	: ticketID(other.ticketID), entryTime(other.entryTime), spot(other.spot) {
	// Copy constructor to create a new ticket with the same details as another ticket
}

int Ticket::getTicketID() const {
	return ticketID;
}

ParkingSpot& Ticket::getSpot() const {
	return spot;
}