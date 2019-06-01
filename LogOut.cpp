#include "LogOut.h"
#include <string>

LogOut::LogOut(std::string id)
{
	this->id = id;
}

bool LogOut::logoutMember(void)
{
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->checkLogoutMember(id)) {
		return true;
	}
	else {
		return false;
	}
}

std::string LogOut::getLogOutID(void) {
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->checkLogoutMember(id)) {
		return memberCollection->getlogoutMemberID();
	}
	else {
		return NULL;
	}

}

LogOutUI::LogOutUI(std::string id)
{
	this->id = id;
}

bool LogOutUI::logOutRequest(void)
{
	LogOut logOutControl(id);
	id = logOutControl.getLogOutID();
	if (id == "") {
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