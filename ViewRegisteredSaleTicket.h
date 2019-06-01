#ifndef VIEWREGISTEREDSALETICKET
#define VIEWREGISTEREDSALETICKET

#include "TicketCollection.h"
#include <vector>

extern Member *curMember;

class ViewRegisteredSaleTicket
{
public:
    ViewRegisteredSaleTicket();
    std::vector<Ticket *> getRegisteredTicket(void);
};

#endif