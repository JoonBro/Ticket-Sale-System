
#ifndef LOGOUT
#define LOGOUT

#include "MemberCollection.h"
#include <string>

class LogOutUI
{
private:
	LogOut logOutControl;
public:
	LogOutUI();
	bool logOutRequest(std::string id);
	std::string printLogOutID();
	
};

class LogOut
{
private:
	MemberCollection memberCollection;
public:
	LogOut();
	bool logoutMember(std::string id);
	std::string getLogOutID();
};

#endif