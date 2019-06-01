#include "Member.h"

Member::Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType)
{
	this->memberId = memberId;
	this->memberPassword = memberPassword;
	this->memberName = memberName;
	this->memberSsn = memberSsn;
	this->currentState = 0; // 현재 로그아웃 상태
	if (memberType == "buyer")
		this->memberUsertype = 1;
	else
		this->memberUsertype = 2;
}

std::string Member::getId(void)
{
	return this->memberId;
}

std::string Member::getPassword(void)
{
	return this->memberPassword;
}

int Member::getMemberUserType(void)
{
	return this->memberUsertype;
}

int Member::getCurrentState(void)
{
	return this->currentState;
}

void Member::setCurrentState(int state)
{
	this->currentState = state;
}

TicketCollection Member::getSaleCollection(void)
{
	return this->saleCollection;
}

TicketCollection Member::getReservedCollection(void)
{
	return this->reservedCollection;
}

TicketCollection Member::getBidCollection(void)
{
	return this->bidCollection;
}