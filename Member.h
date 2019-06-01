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
	int currentState; //0:Logout, 1:Login, 2:Login&
	TicketCollection saleCollection;//판매티켓
	TicketCollection reservedCollection;//구매티켓
	//TicketCollection BidCollection;
public:
	Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType);
	std::string getId(void);
	std::string getPassword(void);
	int getMemberUserType(void);
	int getCurrentState(void);
	void setCurrentState(int state);
	TicketCollection getSaleCollection(void);
	TicketCollection getReservedCollection(void);
};//티켓시스템의 멤버.구매자와 판매자로 나뉜다. 

#endif
