#pragma once

#include "TicketCollection.h"

class SearchAuctionTicket
{
public:
	SearchAuctionTicket();
	std::vector<Ticket *> viewAuctionTicketList(std::string team);
	void bidTicket(int price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat);
};
