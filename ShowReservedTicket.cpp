#include "ShowReservedTicket.h"

ShowReservedTicket::ShowReservedTicket(){}

std::vector<Ticket *> ShowReservedTicket::getReservedTicket(void)
{
    TicketCollection *ticketCollection = TicketCollection::getInstance();
    std::vector<Ticket *> ticketList;
    ticketList = ticketCollection->getReservedTicketList(curUser->getId());
    
    return ticketList;
}

/*
 �ۼ���: ������ 
 ����ð�: 2019-06-02-00:33
 */