#pragma once

#include <string>

class SignUp
{
public:
	SignUp();
	void addMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type);
};
