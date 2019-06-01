#pragma once

#include "MemberCollection.h"
#include <string>

class LogOutUI
{
private:
	std::string id;
public:
	LogOutUI(std::string id = NULL);
	bool logOutRequest(void);
	std::string printLogOutID();
};

class LogOut
{
private:
	std::string id;
public:
	LogOut(std::string id = NULL);
	bool logoutMember(void);
	std::string getLogOutID();
};
