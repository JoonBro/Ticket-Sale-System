#ifndef MEMBER
#define MEMBER

#include <iostream>
#include <string>
#include <vector>
#include "TicketCollection.h"

class Member 
{
private:
	std::string memberId;//아이디
	std::string memberPassword;//비밀번호
	std::string memberName;//이름
	std::string memberSsn;//주민등록번호
	int memberUsertype; //구매자, 판매자
	//TicketCollection saleCollection;//판매티켓
	//TicketCollection reservedCollection;//구매티켓
	//bool memberLogin;//로그인여부, 로그아웃 시 false
					 //TicketCollection BidCollection;
public:
	Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType);
};//티켓시스템의 멤버.구매자와 판매자로 나뉜다. 

#endif