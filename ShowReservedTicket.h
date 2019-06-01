#ifndef SHOWRESERVEDICKET
#define SHOWRESERVEDICKET

#include "TicketCollection.h"
#include <vector>

extern Member *curMember;

class ShowReservedTicket
{
public:
    ShowReservedTicket();
    std::vector<Ticket *> getReservedTicket(void);
};

#endif

/*
 작성자: 조유림 
 변경시간: 2019-06-02-00:33
 */