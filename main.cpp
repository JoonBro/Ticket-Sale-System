#include <iostream>
#include <string>
#include <fstream>
#include "SignUpUI.h"
#include "SignOutUI.h"
#include "LogIn.h"
#include "LogOut.h"
#include "Member.h"
#include "MemberCollection.h"
#include "RegisteringSaleTicketUI.h"
#include "ViewRegisteredSaleTicketUI.h"
#include "SearchTicketUI.h"
#include "SearchAuctionTicketUI.h"
#include "Timer.h"
#include "ShowReservedTicketUI.h"

void doTask(void);
void join(void);
void leave(void);
void login(void);
void logout(void);
void registerSaleTicket(void);
void viewRegisteredSaleTicket(void);
void search(void);
void reserve(void);
void viewAuctionTicket(void);
void enterAuction(void);
void showReservedTicket(void);
void setTime(void);
void changeCurMember(void);
void transitionToGuestSession(void);
void program_exit(void);

std::ifstream input_txt;
std::ofstream output_txt;
Member *curUser;

int main(void)
{
	// ���� ������� ���� �ʱ�ȭ
	input_txt.open("input.txt");
	output_txt.open("output.txt");

	doTask();

	return 0;
}

void doTask(void)
{
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	bool is_program_exit = false;

	while (!is_program_exit)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		input_txt >> menu_level_1 >> menu_level_2;
		//std::cout << menu_level_1 << "\n" << menu_level_2 << "\n";
		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1: // ȸ�� ���� �޴� �κ�
					// join() �Լ����� �ش� ��� ����
				//std::cout << "join\n";
				join();
				break;
			case 2: // ȸ�� Ż�� �޴� �κ�
					// leave() �Լ����� �ش� ��� ����
				//std::cout << "leave\n";
				leave();
				break;
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1: // �α��� �޴� �κ�
					// login() �Լ����� �ش� ��� ����
				//std::cout << "login\n";
				login();
				break;
			case 2: // �α׾ƿ� �޴� �κ�
					// logout() �Լ����� �ش� ��� ����
				//std::cout << "logout\n";
				logout();
				break;
			}
			break;
		case 3:
			switch (menu_level_2)
			{
			case 1: // �Ǹ�Ƽ�� ��� �κ�
					// registerSaleTicket() �Լ����� �ش� ��� ����
				//std::cout << "registerSaleTicket\n";
				registerSaleTicket();
				break;
			case 2: // ��� Ƽ�� ��ȸ
					// viewRegistedSaleTicket() �Լ����� �ش� ��� ����
				//std::cout << "viewRegisteredTicket\n";
				viewRegisteredSaleTicket();
				break;
			}
			break;
		case 4:
			switch (menu_level_2)
			{
			case 1: // Ƽ�� �˻� �κ�
					// search() �Լ����� �ش� ��� ����
				//std::cout << "search\n";
				search();
				break;
			case 2: // Ƽ�� ���� �κ�
					// reserve() �Լ����� �ش� ��� ����
				//std::cout << "reserve\n";
				reserve();
				break;
			case 3: // ��� ���� Ƽ�� �˻� �κ�
					// viewAuctionTicket() �Լ����� �ش� ��� ����
				//std::cout << "viewAuctionTicket\n";
				viewAuctionTicket();
				break;
			case 4: // ��� ���� �κ�
					// enterAuction() �Լ����� �ش� ��� ����
				//std::cout << "enterAuction\n";
				enterAuction();
				break;
			case 5: //���� Ƽ�� ���
				//std::cout << "showReservedTicket\n";
				showReservedTicket();
				break;
			}
			break;
		case 5:
			switch (menu_level_2)
			{
			case 1: // ����ð� ���� �κ�
					// setTime() �Լ����� �ش� ��� ����
				//std::cout << "setTime\n";
				setTime();
				break;
			}
			break;
		case 6:
			switch (menu_level_2)
			{
			case 1: // session ���� �κ�
					// changeCurMember() �Լ����� �ش� ��� ����
				//std::cout << "changeCurMember\n";
				changeCurMember();
				break;
			case 2: // guest session���� ����
					// transitionToGuestSession() �Լ����� �ش� ��� ����
				//std::cout << "transitionToGuestSession\n";
				transitionToGuestSession();
				break;
			}
			break;
		case 7:
			switch (menu_level_2)
			{
			case 1: // 7.1 ���� �޴� �κ�
				//std::cout << "program_exit\n";
				program_exit();
				is_program_exit = true;
				break;
			}
			break;
		}
	}
	return;
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.05.30 01:30
*/
void join(void)
{
	std::string id, passwd, name, ssn, user_type;
	// �Է� ����: ID, ��й�ȣ, �̸�, �ֹι�ȣ, ����������� ���Ϸκ��� ����
	input_txt >> id >> passwd >> name >> ssn >> user_type;
	// �ش� ��ɼ���
	SignUpUI signUpUI;
	signUpUI.signUp(id, passwd, name, ssn, user_type);

	// ��� ����
	output_txt << "1.1 ȸ������\n";
	output_txt << "> " << id << " " << passwd << " " << name << " " << ssn << " " << user_type << "\n";
	output_txt << "\n";
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 03:14
*/
void leave(void)
{
	// �ش� ��� ����
	SignOutUI signOutUI;
	bool flag = signOutUI.signOut(curUser);

	output_txt << "1.2 ȸ��Ż��\n";
	// ��� ����
	output_txt << "> " << curUser->getId();
	if (flag)
		output_txt << "\n";
	else
		output_txt << "�� Ƽ���� �Ǹ����̹Ƿ� �ź�\n";
	output_txt << "\n";
}

/*
�ۼ���: ������
�ۼ� �ð�: 2019.05.31 01:30
*/
void login(void)
{
	std::string id, passwd;
	// �Է� ����: ID, ��й�ȣ, �̸�, �ֹι�ȣ, ����������� ���Ϸκ��� ����
	input_txt >> id >> passwd;

	// �ش� ��ɼ���
	LogInUI logInUI;
	output_txt << "2.1 �α���\n";
	if (logInUI.logInRequest(id, passwd))
		output_txt << "> " << id << " " << passwd << "\n";
	else
		output_txt << "> ���̵�� ��й�ȣ ��ġ���� �ʾ� �ź�\n";

	output_txt << "\n";
}

/*
�ۼ���: ������
�ۼ� �ð�: 2019.05.31 16:00
*/
void logout(void)
{
	// �ش� ��ɼ���
	LogOutUI logOutUI;
	output_txt << "2.2 �α׾ƿ�\n";
	if (logOutUI.logOutRequest())
		output_txt << "> " << logOutUI.printLogOutID() << "\n";
	output_txt << "\n";
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 15:11
*/
void registerSaleTicket(void)
{
	std::string price, date, homeTeam, awayTeam, seat, option;
	// �Է� ����: �������, ��¥-�ð�, Ȩ��, �������, �¼���ġ, ��ż��ÿ��� ���Ϸκ��� ����
	input_txt >> price >> date >> homeTeam >> awayTeam >> seat >> option;
	//std::cout << price << " " << date << " " << homeTeam << " " << awayTeam << " " << seat << " " << option << "\n";
	// �ش� ��� ����
	RegisteringSaleTicketUI registeringSaleTicketUI;
	registeringSaleTicketUI.sendTicketInfo(price, date, homeTeam, awayTeam, seat, option);

	// ��� ����
	output_txt << "3.1 �Ǹ�Ƽ�� ���\n";
	output_txt << "> " << price << " " << date << " " << homeTeam << " " << awayTeam << " " << seat << " " << option << "\n";
	output_txt << "\n";
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 21:40
*/
void viewRegisteredSaleTicket(void)
{
	// �ش� ��� ����
	ViewRegisteredSaleTicketUI viewRegisteredSaleTicketUI;
	std::vector<Ticket *> saleTicketList = viewRegisteredSaleTicketUI.viewSaleTicket();

	output_txt << "3.2 ���Ƽ�� ��ȸ\n";
	for (int i = 0; i<saleTicketList.size(); i++)
	{
		output_txt << "> " << saleTicketList[i]->getTicketPrice() << " " << saleTicketList[i]->getTicketDate();
		output_txt << " " << saleTicketList[i]->getTicketHomeTeam() << " " << saleTicketList[i]->getTicketAwayTeam();
		output_txt << " " << saleTicketList[i]->getTicketSeat() << " " << saleTicketList[i]->getTicketAuction() << " ";
		if (saleTicketList[i]->getSoldDate() == "")
			output_txt << "0\n";
		else
			output_txt << "1\n";
	}
	output_txt << "\n";
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 22:10
*/
void search(void)
{
	// �ش� ��� ����
	SearchTicketUI searchTicketUI;
	searchTicketUI.selectTeam();
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 22:40
*/
void reserve(void)
{
	// search�� extension
	SearchTicketUI searchTicketUI;
	searchTicketUI.reserveTicket();
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 23:36
*/
void viewAuctionTicket(void)
{
	SearchAuctionTicketUI searchAuctionTicketUI;
	searchAuctionTicketUI.selectTeam();
}

/*
�ۼ���: �ΰ���
�ۼ� �ð�: 2019.06.01 23:36
*/
void enterAuction(void)
{
	SearchAuctionTicketUI searchAuctionTicketUI;
	searchAuctionTicketUI.bidForAuction();
}

void setTime(void)
{
	Timer *timer = Timer::getInstance();
	std::string currentTime;
	// �Է� ����: ���� �ð�
	input_txt >> currentTime;
	//std::cout << currentTime << "\n";
	// �ش� ��� ����
	timer->setTime(currentTime);
	// ��� ����
	output_txt << "5.1 ����ð� ����\n";
	output_txt << "> " << currentTime << "\n";
	output_txt << "\n";
}

void changeCurMember(void)
{
	std::string id;
	// �Է� ����: id
	input_txt >> id;

	// �ش� ��� ����
	MemberCollection *memberCollection = MemberCollection::getInstance();
	std::vector<Member *> memberList = memberCollection->getMemberList();
	for (int i = 0; i < memberList.size(); i++)
	{
		if (memberList[i]->getId() == id)
		{
			curUser->setCurrentState(1);
			curUser = memberList[i];
			break;
		}
	}

	// ��� ����
	output_txt << "6.1 session ����\n";
	output_txt << "> " << id << "\n";
	output_txt << "\n";
}

void transitionToGuestSession(void)
{
	curUser = nullptr;
	// ��� ����
	output_txt << "6.2 guest session���� ����\n";
	output_txt << "\n";
}

void program_exit(void)
{
	output_txt << "7.1 ����\n";
	return;
}

/*
�ۼ���: ������
�ð�: 2019-06-02-01:00*/
void showReservedTicket(void)
{
	std::vector<Ticket *> reservedTicketList;//����� Ƽ�ϸ���Ʈ
	ShowReservedTicketUI showReservedTicketUI;//UI����
	reservedTicketList = showReservedTicketUI.showReservedTicket();

	output_txt << "4.5 �������� ��ȸ\n";
	std::vector<Ticket *>::iterator iter;
	for (iter = reservedTicketList.begin();iter != reservedTicketList.end();iter++)
	{
		//���Ű��� ��¥-�ð� Ȩ�� ������� �¼���ġ ���		
		output_txt << (*iter)->getTicketPrice() << " " << (*iter)->getTicketDate() << " " << (*iter)->getTicketHomeTeam() << " " << (*iter)->getTicketAwayTeam() << " " << (*iter)->getTicketSeat() << "\n";
	}
	output_txt << "\n";
}