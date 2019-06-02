#include "SearchTicketUI.h"
#include "SearchTicket.h"
#include <fstream>
#include <string>

extern std::ifstream input_txt;
extern std::ofstream output_txt;
std::string SearchTicketUI::homeTeam;

SearchTicketUI::SearchTicketUI() {}

std::string SearchTicketUI::getHomeTeam(void)
{
	return homeTeam;
}

void SearchTicketUI::setHomeTeam(std::string team)
{
	homeTeam = team;
}

void SearchTicketUI::selectTeam(void)
{
	std::string team;
	// �Է� ����: Ȩ��
	input_txt >> team;
	setHomeTeam(team);

	// �ش� ��� ����
	SearchTicket searchTicket;
	std::vector<Ticket *> availableTicketList;
	availableTicketList = searchTicket.viewAvailableTicketList(team);

	// ��� ����
	output_txt << "4.1 Ƽ�� �˻� ���\n";
	for (int i = 0; i<availableTicketList.size(); i++)
	{
		output_txt << "> " << availableTicketList[i]->getTicketPrice() << " " << availableTicketList[i]->getTicketDate() << " ";
		output_txt << availableTicketList[i]->getTicketHomeTeam() << " " << availableTicketList[i]->getTicketAwayTeam() << " ";
		output_txt << availableTicketList[i]->getTicketSeat() << "\n";
	}
	output_txt << "\n";
}

void SearchTicketUI::reserveTicket(void)
{
	std::string date, awayTeam, seat;
	// �Է� ����: ��¥, �������, �¼�
	input_txt >> date >> awayTeam >> seat;

	// �ش� ��� ����
	SearchTicket searchTicket;
	Ticket * temp = searchTicket.reserveTicket(date, getHomeTeam(), awayTeam, seat);

	// ��� ����
	output_txt << "4.2 Ƽ�� ���� ���\n";
	output_txt << "> " << temp->getTicketPrice() << " " << temp->getTicketDate() << " ";
	output_txt << temp->getTicketHomeTeam() << " " << temp->getTicketAwayTeam() << " ";
	output_txt << temp->getTicketSeat() << "\n";
	output_txt << "\n";
}