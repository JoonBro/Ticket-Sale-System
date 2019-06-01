#include "SearchTicket.h"

SearchTicket::SearchTicket(){}

std::vector<Ticket *> SearchTicket::viewAvailableTicketList(std::string homeTeam)
{
    TicketCollection *ticketCollection = TicketCollection::getInstance();
    std::vector<Ticket *> result;
    result = ticketCollection->getAvailableTicketList(homeTeam);
    return result;
}