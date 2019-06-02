#include "Member.h"

#define BUYER 1
#define SELLER 2

Member::Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType)
{
	this->memberId = memberId;
	this->memberPassword = memberPassword;
	this->memberName = memberName;
	this->memberSsn = memberSsn;
	this->currentState = 0; // 현재 로그아웃 상태
	if (memberType == "buyer")
		this->memberUserType = BUYER;
	else
		this->memberUserType = SELLER;
}

std::string Member::getId(void)
{
	return this->memberId;
}

void Member::setId(std::string id)
{
	this->memberId = id;
}

std::string Member::getPassword(void)
{
	return this->memberPassword;
}

void Member::setPassword(std::string pwd)
{
	this->memberPassword = pwd;
}

std::string Member::getMemberName(void)
{
	return this->memberName;
}

void Member::setMemberName(std::string name)
{
	this->memberName = name;
}

std::string Member::getMemberSsn(void)
{
	return this->memberSsn;
}

void Member::setMemberSsn(std::string ssn)
{
	this->memberSsn = ssn;
}

int Member::getMemberUserType(void)
{
	return this->memberUserType;
}

void Member::setMemberUserType(int type)
{
	this->memberUserType = type;
}

int Member::getCurrentState(void)
{
	return this->currentState;
}

void Member::setCurrentState(int state)
{
	this->currentState = state;
}