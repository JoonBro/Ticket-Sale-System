#include "SignUpUI.h"

SignUpUI::SignUpUI()
{
	signUpControl = SignUp();
}

void SignUpUI::signUp(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	signUpControl.addMember(id, passwd, name, ssn, user_type);
}