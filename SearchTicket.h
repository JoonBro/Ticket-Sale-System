#pragma once

#include "Ticket.h"
#include <vector>

class SearchTicket
{
public:
	SearchTicket();
	std::vector<Ticket *> viewAvailableTicketList(std::string homeTeam);
	Ticket *reserveTicket(std::string date, std::string homeTeam, std::string awayTeam, std::string seat);
};