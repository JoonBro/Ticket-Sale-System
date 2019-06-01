#include "RegisteringSaleTicket.h"
#include "MemberCollection.h"
#include "TicketCollection.h"

extern Member *curMember;

RegisteringSaleTicket::RegisteringSaleTicket(){}

void RegisteringSaleTicket::registerSaleTicket(std::string price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat, std::string option)
{
    TicketCollection *ticketCollection = TicketCollection::getInstance();
    ticketCollection->addTicket(curMember, stoi(price), date, homeTeam, awayTeam, seat, stoi(option));
}