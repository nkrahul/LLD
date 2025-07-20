#include "Ticket.h"

int Ticket::m_ticketCounter = 0; // Initialize static counter

Ticket::Ticket(int spotID)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(std::chrono::system_clock::now()),
	  m_spotID(spotID) {
	// Constructor initializes the ticket with a unique ID and associates it with a parking spot
}

Ticket::Ticket(const Ticket& other)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(other.m_entryTime),
	  m_spotID(other.m_spotID) {
	// Copy constructor: assigns new unique ticket ID, copies entry time, spot, and vehicle
}

int Ticket::getTicketID() const {
	return m_ticketID;
}

