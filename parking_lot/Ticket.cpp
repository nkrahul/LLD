#include "Ticket.h"

int Ticket::m_ticketCounter = 0; // Initialize static counter

Ticket::Ticket(const int level, const int spotID, const std::string& numberPlate)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(std::chrono::system_clock::now()),
	  m_level(level),
	  m_spotID(spotID),
	  m_numberPlate(numberPlate) {
	// Constructor initializes the ticket with a unique ID and associates it with a parking spot
}

Ticket::Ticket(const Ticket& other)
	: m_ticketID(++m_ticketCounter),
	  m_entryTime(other.m_entryTime),
	  m_spotID(other.m_spotID),
	  m_numberPlate(other.m_numberPlate) {
	// Copy constructor: assigns new unique ticket ID, copies entry time, spot, and vehicle
}

int Ticket::getTicketID() const {
	return m_ticketID;
}

int Ticket::getLevelID() const {
	return m_level;
}

int Ticket::getSpotID() const {
	return m_spotID;
}

std::string Ticket::getNumberPlate() const {
	return m_numberPlate;
}