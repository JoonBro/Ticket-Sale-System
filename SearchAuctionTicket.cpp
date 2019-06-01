#include "SearchAuctionTicket.h"

extern Member *curUser;

SearchAuctionTicket::SearchAuctionTicket() {}

std::vector<Ticket *> SearchAuctionTicket::viewAuctionTicketList(std::string team)
{
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	std::vector<Ticket *> ticketList = ticketCollection->getAuctionTicketList(team);
	return ticketList;
}

void SearchAuctionTicket::bidTicket(int price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat)
{
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	ticketCollection->transitionToAuction(curUser->getId(), price, date, homeTeam, awayTeam, seat);
}