#ifndef LOGIN
#define LOGIN

#include "MemberCollection.h"
#include <string>

class LogInUI
{
public:
	LogInUI();
	bool logInRequest(std::string id, std::string passwd);
};

class LogIn
{
public:
	LogIn();
	bool loginMember(std::string id, std::string passwd);
};

#endif