#include "MemberCollection.h"

void MemberCollection::createMember(std::string id, std::string passwd, std::string name, std::string ssn, std::string user_type)
{
	memberList.push_back(Member(id, passwd, name, ssn, user_type)); // Member���� �ּ�ó���� ��������� ���Ŀ� �߰��ϴ� ��������
}

bool MemberCollection::chechloginMember(std::string id, std::string passwd) {
	for (int i = 0; i < memberList.size(); i++) {
		if (id == memberList[i].id && passwd == memberList[i].passwd) {
			retrun true;
		}
	}
	return false;
}