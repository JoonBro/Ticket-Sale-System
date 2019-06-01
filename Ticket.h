#ifndef TICKET
#define TICKET

#include <iostream>
#include <string>

class Ticket 
{
private:
	//int ticketType;//�Ǹ�Ƽ�� Ȥ�� ����Ƽ��
	int ticketPrice;//Ƽ�ϰ���
	std::string ticketTime;//�߱���⳯¥�׽ð� //�Լ����� �ð� parsing �ʿ�
	std::string ticketHomeTeam;//Ȩ��
	std::string ticketAwayTeam;//�������
	std::string ticketSeat;//�¼���ġ
	bool ticketAuction;//auctionƼ�Ͽ���
	bool ticketSold;//�ǸŵǾ����� ����
	int ticketBidPrice;//��������(auction ��)
	//BidCollection ticketBidList;//Ƽ�Ͽ� �ش��ϴ� bidList
public:
	Ticket(int ticketPrice, std::string ticketTime, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction);
};

#endif