#include "MemberCollection.h"

void MemberCollection::createMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	memberList.push_back(Member(id, passwd, name, ssn, user_type)); // Member에서 주석처리한 멤버변수는 추후에 추가하는 방향으로
}

bool MemberCollection::chechloginMember(std::string id, std::string passwd) {
	for (int i = 0; i < memberList.size(); i++) {
		if (id == memberList[i].id && passwd == memberList[i].passwd) {
			retrun true;
		}
	}
	return false;
}

bool MemberCollection::chechlogoutMember(std::string id) {
	for (int i = 0; i < memberList.size(); i++) {
		if (id == memberList[i].id && memberList[i].currentstate == 2) {
			retrun true;
		}
	}
	return false;
}

std::string MemberCollection::getlogoutMemberID() {
	for (int i = 0; i < memberList.size(); i++) {
		if (memberList[i].currentstate == 2) {
			retrun memberList[i].id;
		}
	}
}
