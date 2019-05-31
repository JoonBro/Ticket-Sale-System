#include "LogIn.h"


LogIn::LogIn()
{
	memberCollection = MemberCollection();
}

bool SignUp::loginMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{

	if (memberCollection.chechloginMember(id, passwd)) {
		return true;
	}
	else {
		return false;
	}
}

LogInUI::LogInUI()
{
	logInControl = LogIn();
}

bool LogInUI::logIn(std::string id, std::string passwd)
{
	logInControl.loginMember(id, passwd);
}