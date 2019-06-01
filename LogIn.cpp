#include "LogIn.h"


LogIn::LogIn(){}

bool LogIn::loginMember(std::string id, std::string passwd)
{
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->chechloginMember(id, passwd)) {
		return true;
	}
	else {
		return false;
	}
}

LogInUI::LogInUI(){}

bool LogInUI::logInRequest(std::string id, std::string passwd)
{
	LogIn logInControl;
	logInControl.loginMember(id, passwd);
}