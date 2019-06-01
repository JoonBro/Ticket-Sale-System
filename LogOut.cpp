#include "LogOut.h"
#include <string>

extern Member *curUser;
std::string userId;

LogOut::LogOut() {}

bool LogOut::logoutMember(void)
{
	MemberCollection *memberCollection = MemberCollection::getInstance();
	if (memberCollection->checkLogoutMember(curUser->getId())) {
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

LogOutUI::LogOutUI() {}

bool LogOutUI::logOutRequest(void)
{
	LogOut logOutControl;
	if (logOutControl.logoutMember()) {
		curUser->setCurrentState(0);
		userId = curUser->getId();
		curUser = nullptr;
		return true;
	}
	else {
		return false;
	}
}

std::string LogOutUI::printLogOutID() {
	return userId;
}