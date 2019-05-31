#include "Member.h"

Member::Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType)
{
	this->memberId = memberId;
	this->memberPassword = memberPassword;
	this->memberName = memberName;
	this->memberSsn = memberSsn;
	if (memberType == "buyer")
		this->memberUsertype = 1;
	else
		this->memberUsertype = 2;
}