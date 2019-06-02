#pragma once

#include <iostream>
#include <string>
#include <vector>

class Member
{
private:
	std::string memberId; // 아이디
	std::string memberPassword; // 비밀번호
	std::string memberName; // 이름
	std::string memberSsn; // 주민등록번호
	int memberUserType; // 구매자, 판매자
	int currentState; // 0: Logout, 1:Login, 2: 현재 로그인
public:
	Member(std::string memberId, std::string memberPassword, std::string memberName, std::string memberSsn, std::string memberType);
	std::string getId(void);
	void setId(std::string id);
	std::string getPassword(void);
	void setPassword(std::string pwd);
	std::string getMemberName(void);
	void setMemberName(std::string name);
	std::string getMemberSsn(void);
	void setMemberSsn(std::string ssn);
	int getMemberUserType(void);
	void setMemberUserType(int type);
	int getCurrentState(void);
	void setCurrentState(int state);
};//티켓시스템의 멤버.구매자와 판매자로 나뉜다. 
