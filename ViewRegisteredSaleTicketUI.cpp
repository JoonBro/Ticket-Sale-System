#include "ViewRegisteredSaleTicketUI.h"
#include "ViewRegisteredSaleTicket.h"

ViewRegisteredSaleTicketUI::ViewRegisteredSaleTicketUI() {}

std::vector<Ticket *> ViewRegisteredSaleTicketUI::viewSaleTicket(void)
{
	ViewRegisteredSaleTicket viewReigsteredSaleTicketControl;
	return viewReigsteredSaleTicketControl.getRegisteredTicket();
}