#include "MemberCollection.h"

MemberCollection *MemberCollection::memberCollection = NULL; // singleton

MemberCollection::MemberCollection(){}

MemberCollection *MemberCollection::getInstance(){
	if(memberCollection == NULL)
		memberCollection = new MemberCollection();
	
	return memberCollection;
}

void MemberCollection::createMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	Member *temp = new Member(id, passwd, name, ssn, user_type);
	memberList.push_back(temp); // Member에서 주석처리한 멤버변수는 추후에 추가하는 방향으로
}

void MemberCollection::deleteMember(Member *m)
{
	for(auto it = this->memberList.begin(); it < this->memberList.end(); it++)
	{
		if((*it)->getId() == m->getId())
		{
			this->memberList.erase(it);
			break;
		}
	}
}

bool MemberCollection::chechloginMember(std::string id, std::string passwd) {
	for (auto it = this ->memberList.begin(); it < this->memberList.end(); it++)
	{
		if ((*it)->getId() == id && (*it)->getPassword() == passwd) {
			return true;
		}
	}
	return false;
}

bool MemberCollection::chechlogoutMember(std::string id) {
	for (auto it = this -> memberList.begin(); it < this->memberList.end(); it++)
	{
		if ((*it)->getId() == id && (*it)->getCurrentState == 2) {
			return true;
		}
	}
	return false;
}

std::string MemberCollection::getlogoutMemberID() {
	for (auto it = this -> memberList.begin(); it < this->memberList.end(); it++)
	{
		if ((*it)->getCurrentState == 2) {
			return (*it)->getId();
		}
	}
}
