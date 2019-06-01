#include "SignOut.h"
#include "MemberCollection.h"
#include "TicketCollection.h"

SignOut::SignOut(){}

bool SignOut::deleteMember(Member *m)
{
    MemberCollection *memberCollection = MemberCollection::getInstance();
    if(m->getMemberUserType == 2) // seller
    {
        // 제약 조건 확인
        TicketCollection *ticketCollection = TicketCollection::getInstance();
        std::vector<Ticket *> saleTicketList = ticketCollection->getSaleTicketList(m->getId());
        // 판매 중인 티켓이 있다면
        if(saleTicketList.size())
            return false;
    }
    memberCollection -> deleteMember(m);
    return true;
}