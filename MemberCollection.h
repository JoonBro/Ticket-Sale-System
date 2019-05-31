#ifndef MEMBERCOLLECTION
#define MEMBERCOLLECTION

#include "Member.h"

class MemberCollection
{
private:
	std::vector<Member> memberList;
public:
	void createMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type);
	bool chechloginMember(std::string id, std::string passwd);
};

#endif