#include "ShowReservedTicketUI.h"
#include "ShowReservedTicket.h"

ShowReservedTicketUI::ShowReservedTicketUI() {}

std::vector<Ticket *> ShowReservedTicketUI::showReservedTicket(void)
{
	ShowReservedTicket showReservedTicketControl;
	return showReservedTicketControl.getReservedTicket();
}

/*
�ۼ���: ������
����ð�: 2019-06-02-00:33
*/