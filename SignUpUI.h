#ifndef SIGNUPUI
#define SIGNUPUI

#include "SignUp.h"
#include <string>

class SignUpUI
{
public:
	SignUpUI();
	void signUp(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type);
};

#endif