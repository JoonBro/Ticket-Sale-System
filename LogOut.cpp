#include "LogOut.h"
#include <string>

LogOut::LogOut(std::string id = NULL)
{
	this->id = id;
}

bool LogOut::logoutMember(void)
{
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->chechlogoutMember(id)) {
		return true;
	}
	else {
		return false;
	}
}

std::string LogOut::getLogOutID(void) {
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->chechlogoutMember(id)) {
		return memberCollection->getlogoutMemberID();
	}
	else {
		return NULL;
	}
	
}

LogOutUI::LogOutUI(std::string id = NULL) 
{
	this->id = id;
}

bool LogOutUI::logOutRequest(void)
{
	LogOut logOutControl(id);
	id = logOutControl.getLogOutID();
	if (!id.compare(NULL)) {
		return false;
	}
	if (logOutControl.logoutMember()) {
		return true;
	}
	else {
		return false;
	}
}

std::string LogOutUI::printLogOutID() {
	LogOut logOutControl(id);
	return logOutControl.getLogOutID();
}