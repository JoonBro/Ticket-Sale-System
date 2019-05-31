#ifndef MEMBERCOLLECTION
#define MEMBERCOLLECTION

#include "Member.h"

// updated singleton pattern on memberCollection
// Min Kyungate 6/1 03:10
class MemberCollection
{
private:
	static MemberCollection *memberCollection;
	std::vector<Member*> memberList;
	MemberCollection();
public:
	void createMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type);
	void deleteMember(Member *m);
	static MemberCollection *getInstance();
	bool chechloginMember(std::string id, std::string passwd);
	bool chechlogoutMember(std::string id);
	std::string getlogoutMemberID();
};

#endif
