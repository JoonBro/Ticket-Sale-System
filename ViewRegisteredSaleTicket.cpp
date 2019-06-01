#include "ViewRegisteredSaleTicket.h"

ViewRegisteredSaleTicket::ViewRegisteredSaleTicket(){}

std::vector<Ticket *> ViewRegisteredSaleTicket::getRegisteredTicket(void)
{
    TicketCollection *ticketCollection = TicketCollection::getInstance();
    std::vector<Ticket *> ticketList;
    ticketList = ticketCollection->getSaleTicketList(curMember->getId());
    
    return ticketList;
}