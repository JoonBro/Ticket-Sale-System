#include "SearchTicketUI.h"
#include "SearchTicket.h"
#include <fstream>
#include <string>

extern std::ifstream input_txt;
extern std::ofstream output_txt;

SearchTicketUI::SearchTicketUI(){}

std::string SearchTicketUI::getHomeTeam(void)
{
    return this->homeTeam;
}

void SearchTicketUI::selectTeam(void)
{
    std::string team;
    // 입력 형식: 홈팀
    input_txt >> team;

    // 해당 기능 수행
    SearchTicket searchTicket;
    std::vector<Ticket *> availableTicketList;
    availableTicketList = searchTicket.viewAvailableTicketList(team);

    // 출력 형식
    output_txt << "4.1 티켓 검색 기능\n";
    for(int i=0; i<availableTicketList.size(); i++)
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
    // 입력 형식: 날짜, 어웨이팀, 좌석
    input_txt >> date >> awayTeam >> seat;

    // 해당 기능 수행
    SearchTicket searchTicket;
    Ticket * temp = searchTicket.reserveTicket(getHomeTeam(), date, awayTeam, seat);

    // 출력 형식
    output_txt << "4.2 티켓 예약 기능\n";
    output_txt << "> " << temp->getTicketPrice() << " " << temp->getTicketDate() << " ";
    output_txt << temp->getTicketHomeTeam() << " " << temp->getTicketAwayTeam() << " ";
    output_txt << temp->getTicketSeat() << "\n";
    output_txt << "\n";
}