#include "LogOut.h"


LogOut::LogOut()
{
	memberCollection = MemberCollection();
}

bool LogOut::logoutMember(std::string id)
{
	
	if (memberCollection.chechlogoutMember(id)) {
		return true;
	}
	else {
		return false;
	}
}

std::string LogOut::getLogOutID() {
	if (memberCollection.chechlogoutMember(id)) {
		return memberCollection.getlogoutMemberID();
	}
	else {
		return NULL;
	}
	
}

LogOutUI::LogOutUI()
{
	logOutControl = LogOut();
}

bool LogOutUI::logOutRequest()
{
	std::string id;
	id = logOutControl.getLogOutID();
	if (id == NULL) {
		return false;
	}
	if (logOutControl.logoutMember(id)) {
		return true;
	}
	else {
		return false;
	}
}

std::string printLogOutID() {
	return logOutControl.getLogOutID();
}