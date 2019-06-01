#include "SearchTicket.h"
#include "TicketCollection.h"

extern Member *curUser;

SearchTicket::SearchTicket() {}

std::vector<Ticket *> SearchTicket::viewAvailableTicketList(std::string homeTeam)
{
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	std::vector<Ticket *> result;
	result = ticketCollection->getAvailableTicketList(homeTeam);
	return result;
}

Ticket *SearchTicket::reserveTicket(std::string date, std::string homeTeam, std::string awayTeam, std::string seat)
{
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	Ticket *ticket = ticketCollection->reserveTicket(curUser->getId(), date, homeTeam, awayTeam, seat);
	return ticket;
}