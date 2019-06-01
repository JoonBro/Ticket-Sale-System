#pragma once

#include "MemberCollection.h"
#include <string>

class LogOutUI
{
public:
	LogOutUI();
	bool logOutRequest(void);
	std::string printLogOutID();
};

class LogOut
{
private:
	std::string id;
public:
	LogOut();
	bool logoutMember(void);
	std::string getLogOutID();
};
