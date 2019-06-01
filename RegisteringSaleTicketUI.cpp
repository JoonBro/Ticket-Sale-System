#include "RegisteringSaleTicketUI.h"
#include "RegisteringSaleTicket.h"

RegisteringSaleTicketUI::RegisteringSaleTicketUI() {}

void RegisteringSaleTicketUI::sendTicketInfo(std::string price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat, std::string option)
{
	RegisteringSaleTicket registeringSaleTicket;
	registeringSaleTicket.registerSaleTicket(price, date, homeTeam, awayTeam, seat, option);
}