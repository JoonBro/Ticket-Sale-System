#ifndef SHOWRESERVEDICKET
#define SHOWRESERVEDICKET

#include "TicketCollection.h"
#include <vector>

extern Member *curUser;

class ShowReservedTicket
{
public:
	ShowReservedTicket();
	std::vector<Ticket *> getReservedTicket(void);
};

#endif

/*
�ۼ���: ������
����ð�: 2019-06-02-00:33
*/