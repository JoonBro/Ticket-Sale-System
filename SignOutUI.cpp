#include "SignUpUI.h"
#include "SignUp.h"

SignUpUI::SignUpUI() {}

void SignUpUI::signUp(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	SignUp signUp;
	signUp.addMember(id, passwd, name, ssn, user_type);
}