#pragma once

#include "TicketCollection.h"
#include <vector>

class ViewRegisteredSaleTicketUI
{
public:
	ViewRegisteredSaleTicketUI();
	std::vector<Ticket *> viewSaleTicket(void);
};