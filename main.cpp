#include <iostream>
#include <string>
#include <fstream>
#include "SignUpUI.h"
#include "SignOutUI.h"
#include "LogIn.h"
#include "LogOut.h"
#include "MemberCollection.h"
#include "RegisteringSaleTicketUI.h"
#include "ViewRegisteredSaleTicketUI.h"
#include "SearchTicketUI.h"
#include "SearchAuctionTicketUI.h"
#include "Timer.h"

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
	// 파일 입출력을 위한 초기화
	input_txt.open("input.txt");
	output_txt.open("output.txt");

	doTask();

	return 0;
}

void doTask(void)
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	bool is_program_exit = false;

	while (!is_program_exit)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		input_txt >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1: // 회원 가입 메뉴 부분
				// join() 함수에서 해당 기능 수행
				join();
				break;
			case 2: // 회원 탈퇴 메뉴 부분
				// leave() 함수에서 해당 기능 수행
				leave(); 
				break;
			}
		case 2:
			switch (menu_level_2)
			{
			case 1: // 로그인 메뉴 부분
				// login() 함수에서 해당 기능 수행
				login();
				break;
			case 2: // 로그아웃 메뉴 부분
				// logout() 함수에서 해당 기능 수행
				logout();
				break;
			}
		case 3:
			switch (menu_level_2)
			{
			case 1: // 판매티켓 등록 부분
				// registerSaleTicket() 함수에서 해당 기능 수행
				registerSaleTicket();
				break;
			case 2: // 등록 티켓 조회
				// viewRegistedSaleTicket() 함수에서 해당 기능 수행
				viewRegisteredSaleTicket();
				break;
			}
		case 4:
			switch (menu_level_2)
			{
			case 1: // 티켓 검색 부분
				// search() 함수에서 해당 기능 수행
				search();
				break;
			case 2: // 티켓 예약 부분
				// reserve() 함수에서 해당 기능 수행
				reserve();
				break;
			case 3: // 경매 중인 티켓 검색 부분
				// viewAuctionTicket() 함수에서 해당 기능 수행
				viewAuctionTicket();
				break;
			case 4: // 경매 참여 부분
				// enterAuction() 함수에서 해당 기능 수행
				enterAuction();
				break;
			case 5: //예약 티켓 출력
				showReservedTicket();

				break;
			}
		case 5:
			switch (menu_level_2)
			{
			case 1: // 현재시간 설정 부분
				// setTime() 함수에서 해당 기능 수행
				setTime();
				break;
			}
		case 6:
			switch (menu_level_2)
			{
			case 1: // session 변경 부분
				// changeCurMember() 함수에서 해당 기능 수행
				changeCurMember();
				break;
			case 2: // guest session으로 변경
				// transitionToGuestSession() 함수에서 해당 기능 수행
				transitionToGuestSession();
				break;
			}
		case 7:
			switch (menu_level_2)
			{
			case 1: // 7.1 종료 메뉴 부분
				program_exit();
				is_program_exit = true;
				break;
			}
		}
	}
	return;
}

/*
작성자: 민경태
작성 시간: 2019.05.30 01:30
*/
void join(void)
{
	std::string id, passwd, name, ssn, user_type;
	// 입력 형식: ID, 비밀번호, 이름, 주민번호, 사용자유형을 파일로부터 읽음
	input_txt >> id >> passwd >> name >> ssn >> user_type;

	// 해당 기능수행
	SignUpUI signUpUI;
	signUpUI.signUp(id, passwd, name, ssn, user_type);

	// 출력 형식
	output_txt << "1.1 회원가입\n";
	output_txt << "> " << id << " " << passwd << " " << name << " " << ssn << " " << user_type << "\n";
	output_txt << "\n";
}

/*
작성자: 민경태
작성 시간: 2019.06.01 03:14
*/
void leave(void)
{
	// 해당 기능 수행
	SignOutUI signOutUI;
	bool flag = signOutUI.signOut(curUser);

	output_txt << "1.2 회원탈퇴\n";
	// 출력 형식
	output_txt << "> " << curUser -> getId();
	if(flag)
		output_txt << "\n";
	else
		output_txt << "가 티켓을 판매중이므로 거부\n";
	output_txt << "\n";
}

/*
작성자: 박준형
작성 시간: 2019.05.31 01:30
*/
void login(void)
{
	std::string id, passwd;
	// 입력 형식: ID, 비밀번호, 이름, 주민번호, 사용자유형을 파일로부터 읽음
	input_txt >> id >> passwd;

	// 해당 기능수행
	LogInUI logInUI;
	output_txt << "2.1 로그인\n";
	if (logInUI.logInRequest(id, passwd)) 
		output_txt << "> " << id << " " << passwd << "\n";
	else
		output_txt << "> 아이디와 비밀번호 일치하지 않아 거부\n";
	
	output_txt << "\n";
}

/*
작성자: 박준형
작성 시간: 2019.05.31 16:00
*/
void logout(void)
{
	std::string id;
	input_txt >> id;

	// 해당 기능수행
	LogOutUI logOutUI(id);
	output_txt << "2.2 로그아웃\n";
	if (logOutUI.logOutRequest())
		output_txt << "> " << logOutUI.printLogOutID() << "\n";

	output_txt << "\n";
}

/*
작성자: 민경태
작성 시간: 2019.06.01 15:11
*/
void registerSaleTicket(void)
{
	std::string price, date, homeTeam, awayTeam, seat, option;
	// 입력 형식: 희망가격, 날짜-시간, 홈팀, 어웨이팀, 좌석위치, 경매선택여부 파일로부터 읽음
	input_txt >> price >> date >> homeTeam >> awayTeam >> seat >> option;

	// 해당 기능 수행
	RegisteringSaleTicketUI registeringSaleTicketUI;
	registeringSaleTicketUI.sendTicketInfo(price, date, homeTeam, awayTeam, seat, option);

	// 출력 형식
	output_txt << "3.1 판매티켓 등록\n";
	output_txt << "> " << price << " " << date << " " << homeTeam << " " << awayTeam << " " << seat << " " << option << "\n";
	output_txt << "\n";
}

/*
작성자: 민경태
작성 시간: 2019.06.01 21:40
*/
void viewRegisteredSaleTicket(void)
{
	// 해당 기능 수행
	ViewRegisteredSaleTicketUI viewRegisteredSaleTicketUI;
	std::vector<Ticket *> saleTicketList = viewRegisteredSaleTicketUI.viewSaleTicket();

	output_txt << "3.2 등록티켓 조회\n";
	for(int i=0; i<saleTicketList.size(); i++)
	{
		output_txt <<"> " << saleTicketList[i]->getTicketPrice() << " " << saleTicketList[i]->getTicketDate();
		output_txt << " " << saleTicketList[i]->getTicketHomeTeam() << " " << saleTicketList[i]->getTicketAwayTeam();
		output_txt << " " << saleTicketList[i]->getTicketSeat() << " " << saleTicketList[i]->getTicketAuction() <<  " ";
		if(saleTicketList[i]->getReservedDate == "")
			output_txt << "0\n";
		else
			output_txt << "1\n";
	}
	output_txt << "\n";
}

/*
작성자: 민경태
작성 시간: 2019.06.01 22:10
*/
void search(void)
{
	// 해당 기능 수행
	SearchTicketUI searchTicketUI;
	searchTicketUI.selectTeam();
}

/*
작성자: 민경태
작성 시간: 2019.06.01 22:40
*/
void reserve(void)
{
	// search의 extension
	SearchTicketUI searchTicketUI;
	searchTicketUI.reserveTicket();
}

/*
작성자: 민경태
작성 시간: 2019.06.01 23:36
*/
void viewAuctionTicket(void)
{
	SearchAuctionTicketUI searchAuctionTicketUI;
	searchAuctionTicketUI.selectTeam();
}

/*
작성자: 민경태
작성 시간: 2019.06.01 23:36
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
	// 입력 형식: 현재 시간
	input_txt >> currentTime;

	// 해당 기능 수행
	timer->setTime(currentTime);
	// 출력 형식
	output_txt << "5.1 현재시간 설정\n";
	output_txt << "> " << currentTime << "\n";
	output_txt << "\n";
}

void changeCurMember(void)
{
	std::string id;
	// 입력 형식: id
	input_txt >> id;

	// 해당 기능 수행
	MemberCollection *memberCollection = MemberCollection::getInstance();
	std::vector<Member *> memberList = memberCollection->getMemberList();
	for(int i=0; i<memberList.size(); i++)
		if(memberList[i]->getId() == id && memberList[i]->getCurrentState == 1)
		{
			curUser = memberList[i];
			break;
		}
	
	// 출력 형식
	output_txt << "6.1 session 변경\n";
	output_txt << "> " << id << "\n";
	output_txt << "\n";
}

void transitionToGuestSession(void)
{
	curUser = nullptr;
	// 출력 형식
	output_txt << "6.2 guest session으로 변경\n";
	output_txt << "\n";
}

void program_exit(void)
{
	output_txt << "7.1 종료\n";
	return;
}

/*
작성자: 조유림
시각: 2019-06-02-01:00*/
void showReservedTicket(void)
{
	std::vector<Ticket *> reservedTicketList;//예약된 티켓리스트
	showReservedTicketUI showReservedTicketUI;//UI생성
	reservedTicketList = showReservedTicketUI.showReservedTicket();

	output_txt << "4.5 예약정보 조회\n";
	vector<int>::iterator iter;
	for(iter=reservedTicketList.begin();iter != reservedTicketList.end();iter++)
	{
		//구매가격 날짜-시간 홈팀 어웨이팀 좌석위치 출력		
		output_txt << iter->ticketPrice << " "<< iter->ticketDate << " " << iter->ticketHomeTeam << " " << iter->ticketAwayTeam << " " << iter->ticketSeat << "\n";
	}

}