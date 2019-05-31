#include <iostream>
#include <string>
#include <fstream>
#include "SignUpUI.h"
#include "LogInUI.h"

void doTask(void);
void join(void);
void program_exit(void);

std::ifstream input_txt;
std::ofstream output_txt;

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
			case 1: //회원 가입 메뉴 부분
				// join() 함수에서 해당 기능 수행
				join();
				break;
			case 2:
				break;
			}
		case 2:
			switch (menu_level_2)
			{
			case 1:
				login();
				break;
			case 2:
				break;
			}
		case 3:
			switch (menu_level_2)
			{
			case 1:
				break;
			case 2:
				break;
			}
		case 4:
			switch (menu_level_2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
		case 5:
			switch (menu_level_2)
			{
			case 1:
				break;
			}
		case 6:
			switch (menu_level_2)
			{
			case 1:
				break;
			case 2:
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
	output_txt << ">" << id << " " << passwd << " " << name << " " << ssn << " " << user_type << "\n";
	return;
}

/*
작성자: 박준형
작성 시간: 2019.05.31 01:30
*/
void login(void)
{
	std::string id, passwd
		// 입력 형식: ID, 비밀번호, 이름, 주민번호, 사용자유형을 파일로부터 읽음
		input_txt >> id >> passwd;

	// 해당 기능수행
	LogInUI logInUI;
	if (logInUI.logIn(id, passwd)) {
		output_txt << "2.1 로그인\n";
		output_txt << ">" << id << " " << passwd << "\n";
	}



	return;
}


void program_exit(void)
{
	output_txt << "7.1 종료\n";
	return;
}