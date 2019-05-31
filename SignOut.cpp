#include "SignOut.h"
#include "MemberCollection.h"

SignOut::SignOut(){}

bool SignOut::deleteMember(Member *m)
{
    MemberCollection *memberCollection = MemberCollection::getInstance();
    if(m->getMemberUserType == 2) // seller
    {
        // 제약 조건 확인
        
    }
    memberCollection -> deleteMember(m);
    return true;
}