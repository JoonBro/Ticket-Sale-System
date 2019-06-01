#ifndef VIEWREGISTEREDSALETICKETUI
#define VIEWREGISTEREDSALETICKETUI

#include "TicketCollection.h"
#include <vector>

class ViewRegisteredSaleTicketUI
{
public:
    ViewRegisteredSaleTicketUI();
    std::vector<Ticket *> viewSaleTicket(void);
};

#endif