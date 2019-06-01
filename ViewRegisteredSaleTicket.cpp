#include "ViewRegisteredSaleTicket.h"

extern Member *curUser;

ViewRegisteredSaleTicket::ViewRegisteredSaleTicket() {}

std::vector<Ticket *> ViewRegisteredSaleTicket::getRegisteredTicket(void)
{
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	std::vector<Ticket *> ticketList = ticketCollection->getSaleTicketList(curUser->getId());

	return ticketList;
}