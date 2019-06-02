#include "SignOut.h"
#include "MemberCollection.h"
#include "TicketCollection.h"

SignOut::SignOut() {}

bool SignOut::deleteMember(Member *m)
{
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (m->getMemberUserType() == 2) // seller
	{
		// ���� ���� Ȯ��
		TicketCollection *ticketCollection = TicketCollection::getInstance();
		std::vector<Ticket *> saleTicketList = ticketCollection->getSaleTicketList(m->getId());
		// �Ǹ� ���� Ƽ���� �ִٸ�
		if (saleTicketList.size())
			return false;
	}
	memberCollection->deleteMember(m);
	return true;
}