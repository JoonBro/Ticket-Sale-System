#ifndef TICKETCOLLECTION
#define TICKETCOLLECTION

#include "Ticket.h"
#include <vector>

class TicketCollection 
{
private:
	std::vector<Ticket> ticketList;
public:
	TicketCollection();
	std::vector<Ticket> getTicketList(void);
};

#endif