#ifndef TICKET
#define TICKET

#include <iostream>
#include <string>

class Ticket 
{
private:
	int ticketType;//�Ǹ�Ƽ�� Ȥ�� ����Ƽ��
	std::string ticketHomeTeam;//Ȩ��
	std::string ticketAwayTeam;//�������
	std::string ticketTime;//�߱���⳯¥�׽ð� //�Լ����� �ð� parsing �ʿ�
	std::string ticketSeat;//�¼���ġ
	bool ticketAuction;//auctionƼ�Ͽ���
	bool ticketSold;//�ǸŵǾ����� ����
	int ticketPrice;//Ƽ�ϰ���
	int ticketBidPrice;//��������(auction ��)
	//BidCollection ticketBidList;//Ƽ�Ͽ� �ش��ϴ� bidList
public:
};

#endif