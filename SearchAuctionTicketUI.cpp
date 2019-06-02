#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicket.h"
#include "TicketCollection.h"
#include <fstream>
#include <string>

extern std::ifstream input_txt;
extern std::ofstream output_txt;
std::string SearchAuctionTicketUI::homeTeam;

SearchAuctionTicketUI::SearchAuctionTicketUI() {}

std::string SearchAuctionTicketUI::getHomeTeam(void)
{
	return homeTeam;
}

void SearchAuctionTicketUI::setHomeTeam(std::string team)
{
	homeTeam = team;
}

void SearchAuctionTicketUI::selectTeam(void)
{
	std::string team;
	// �Է� ����: Ȩ��
	input_txt >> team;
	setHomeTeam(team);

	// �ش� ��� ����
	SearchAuctionTicket searchAuctionTicket;
	std::vector<Ticket *> ticketList = searchAuctionTicket.viewAuctionTicketList(team);

	// ��� ����
	output_txt << "4.3 ��� ���� Ƽ�� �˻�\n";
	for (int i = 0; i<ticketList.size(); i++)
	{
		output_txt << "> " << ticketList[i]->getTicketDate() << " " << ticketList[i]->getTicketHomeTeam() << " ";
		output_txt << ticketList[i]->getTicketAwayTeam() << " " << ticketList[i]->getTicketSeat() << " ";
		output_txt << ticketList[i]->remainingAuctionTime() << "\n";
	}
	output_txt << "\n";
}

void SearchAuctionTicketUI::bidForAuction(void)
{
	std::string date, awayTeam, seat, price;
	// �Է� ����: ��¥, �������, �¼�, ����
	input_txt >> date >> awayTeam >> seat >> price;

	// �ش� ��� ����
	SearchAuctionTicket searchAuctionTicket;
	searchAuctionTicket.bidTicket(stoi(price), date, getHomeTeam(), awayTeam, seat);

	// ��� ����
	output_txt << "4.4 ��� ����\n";
	output_txt << "> " << price << "\n";
	output_txt << "\n";
}