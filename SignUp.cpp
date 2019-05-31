#include "SignUp.h"

SignUp::SignUp()
{
	memberCollection = MemberCollection();
}

void SignUp::addMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	memberCollection.createMember(id, passwd, name, ssn, user_type);
}