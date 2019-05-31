#ifndef LOGIN
#define LOGIN

#include "MemberCollection.h"
#include <string>

class LogInUI
{
private:
	LogIn logInControl;
public:
	LogInUI();
	bool logIn(std::string id, std::string passwd);
};

class LogIn
{
private:
	MemberCollection memberCollection;
public:
	LogIn();
	bool loginMember(std::string id, std::string passwd);
};

#endif