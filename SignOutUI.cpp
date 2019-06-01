#include "SignOutUI.h"
#include "SignOut.h"
#include "MemberCollection.h"

SignOutUI::SignOutUI() {}

bool SignOutUI::signOut(Member *m)
{
	SignOut signOut;
	bool flag = signOut.deleteMember(m);
	return flag;
}