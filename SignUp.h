#ifndef SIGNUP
#define SIGNUP

#include "MemberCollection.h"

class SignUp
{
private:
	MemberCollection memberCollection;
public:
	SignUp();
	void addMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type);
};

#endif