#pragma once

#include "TicketCollection.h"
#include <vector>

class ViewRegisteredSaleTicket
{
public:
	ViewRegisteredSaleTicket();
	std::vector<Ticket *> getRegisteredTicket(void);
};