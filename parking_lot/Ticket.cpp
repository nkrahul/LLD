#include "Ticket.h"

int Ticket::m_ticketCounter = 0; // Initialize static counter

Ticket::Ticket(int spotID, std::shared_ptr<Vehicle> vehicle)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(std::chrono::system_clock::now()),
	  m_spotID(spotID),
	  m_vehicle(vehicle) {
	// Constructor initializes the ticket with a unique ID and associates it with a parking spot
}

Ticket::Ticket(const Ticket& other)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(other.m_entryTime),
	  m_spotID(other.m_spotID),
	  m_vehicle(other.m_vehicle) {
	// Copy constructor: assigns new unique ticket ID, copies entry time, spot, and vehicle
}

int Ticket::getTicketID() const {
	return m_ticketID;
}

std::shared_ptr<ParkingSpot> Ticket::getSpot() {
	return m_spot;
}

