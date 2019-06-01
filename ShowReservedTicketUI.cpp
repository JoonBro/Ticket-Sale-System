#include "ShowReservedTicketUI.h"
#include "ShowReservedTicket.h"

ShowReservedTicketUI::ShowReservedTicketUI(){}

std::vector<Ticket *> ShowReservedTicketUI::showReservedTicket(void)
{
    ShowReservedTicket showReservedTicketControl;
    return showReservedTicketControl.getReservedTicket();
}

/*
 작성자: 조유림 
 변경시간: 2019-06-02-00:33
 */