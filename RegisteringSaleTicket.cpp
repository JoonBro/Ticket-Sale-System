#include "RegisteringSaleTicket.h"
#include "MemberCollection.h"
#include "TicketCollection.h"

extern Member *curMember;

RegisteringSaleTicket::RegisteringSaleTicket(){}

void RegisteringSaleTicket::registerSaleTicket(std::string price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat, std::string option)
{
    TicketCollection tc;
    tc = curMember->getReservedCollection();
    std::vector<Ticket> reservedTicketList = tc.getTicketList();
    // 추후 제약조건 추가
    reservedTicketList.push_back(Ticket(stoi(price), date, homeTeam, awayTeam, seat, stoi(option)));
}