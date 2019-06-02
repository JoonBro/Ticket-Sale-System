#pragma once

#include <iostream>
#include <string>
#include <vector>

class Member
{
private:
	std::string memberId; // ���̵�
	std::string memberPassword; // ��й�ȣ
	std::string memberName; // �̸�
	std::string memberSsn; // �ֹε�Ϲ�ȣ
	int memberUserType; // ������, �Ǹ���
	int currentState; // 0: Logout, 1:Login, 2: ���� �α���
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
};//Ƽ�Ͻý����� ���.�����ڿ� �Ǹ��ڷ� ������. 
