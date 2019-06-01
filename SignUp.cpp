#include "SignUp.h"
#include "MemberCollection.h"

SignUp::SignUp() {}

void SignUp::addMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	// singleton pattern
	MemberCollection *memberCollection = MemberCollection::getInstance();
	memberCollection->createMember(id, passwd, name, ssn, user_type);
}