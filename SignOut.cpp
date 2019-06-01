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
        TicketCollection tc;
        tc = m->getSaleCollection();
        std::vector<Ticket> saleTicketCollection = tc.getTicketList();
        // 티켓을 가지고 있으면 회원 탈퇴 불가능
        if(saleTicketCollection.size())
            return false;
    }
    memberCollection -> deleteMember(m);
    return true;
}