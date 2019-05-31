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

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1: //ȸ�� ���� �޴� �κ�
				// join() �Լ����� �ش� ��� ����
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
			case 1: // 7.1 ���� �޴� �κ�

				program_exit();
				is_program_exit = true;
				break;
			}
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
	output_txt << ">" << id << " " << passwd << " " << name << " " << ssn << " " << user_type << "\n";
	return;
}

/*
�ۼ���: ������
�ۼ� �ð�: 2019.05.31 01:30
*/
void login(void)
{
	std::string id, passwd
		// �Է� ����: ID, ��й�ȣ, �̸�, �ֹι�ȣ, ����������� ���Ϸκ��� ����
		input_txt >> id >> passwd;

	// �ش� ��ɼ���
	LogInUI logInUI;
	if (logInUI.logIn(id, passwd)) {
		output_txt << "2.1 �α���\n";
		output_txt << ">" << id << " " << passwd << "\n";
	}



	return;
}


void program_exit(void)
{
	output_txt << "7.1 ����\n";
	return;
}