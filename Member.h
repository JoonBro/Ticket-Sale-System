#ifndef MEMBER
#define MEMBER

#include <iostream>
#include <string>
#include <vector>
#include "TicketCollection.h"

class Member 
{
private:
	std::string memberId;//���̵�
	std::string memberPassword;//��й�ȣ
	std::string memberName;//�̸�
	std::string memberSsn;//�ֹε�Ϲ�ȣ
	int memberUsertype; //������, �Ǹ���
	//TicketCollection saleCollection;//�Ǹ�Ƽ��
	//TicketCollection reservedCollection;//����Ƽ��
	//bool memberLogin;//�α��ο���, �α׾ƿ� �� false
					 //TicketCollection BidCollection;
public:
	Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType);
};//Ƽ�Ͻý����� ���.�����ڿ� �Ǹ��ڷ� ������. 

#endif