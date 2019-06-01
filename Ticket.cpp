#include "Ticket.h"

Ticket::Ticket(int ticketPrice, std::string ticketTime, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction)
{
    this->ticketPrice = ticketPrice;
    this->ticketTime = ticketTime;
    this->ticketHomeTeam = ticketHomeTeam;
    this->ticketAwayTeam = ticketAwayTeam;
    this->ticketSeat = ticketSeat;
    this->ticketAuction = ticketAuction;
}