#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicket.h"
#include "TicketCollection.h"
#include <fstream>
#include <string>

extern std::ifstream input_txt;
extern std::ofstream output_txt;

SearchAuctionTicketUI::SearchAuctionTicketUI(){}

std::string SearchAuctionTicketUI::getHomeTeam(void)
{
    return this->homeTeam;
}

void SearchAuctionTicketUI::setHomeTeam(std::string team)
{
    this->homeTeam = team;
}

void SearchAuctionTicketUI::selectTeam(void)
{
    std::string team;
    // 입력 형식: 홈팀
    input_txt >> team;
    setHomeTeam(team);

    // 해당 기능 수행
    SearchAuctionTicket searchAuctionTicket;
    std::vector<Ticket *> ticketList = searchAuctionTicket.viewAuctionTicketList(team);

    // 출력 형식
    output_txt << "4.3 경매 중인 티켓 검색\n";
    for(int i=0; i<ticketList.size(); i++)
    {
        output_txt << "> " << ticketList[i]->getTicketDate() << " " << ticketList[i]->getTicketHomeTeam() <<" ";
        output_txt << ticketList[i]->getTicketAwayTeam() <<" " << ticketList[i]->getTicketSeat() << " ";
        output_txt << ticketList[i]->remainingAuctionTime() << "\n";
    }
    output_txt << "\n";
}

void SearchAuctionTicketUI::bidForAuction(void)
{
    std::string date, awayTeam, seat, price;
    // 입력 형식: 날짜, 어웨이팀, 좌석, 가격
    input_txt >> date >> awayTeam >> seat >> price;

    // 해당 기능 수행
    SearchAuctionTicket searchAuctionTicket;
    searchAuctionTicket.bidTicket(stoi(price), date, getHomeTeam(), awayTeam, seat);

    // 출력 형식
    output_txt << "4.4 경매 참여\n";
    output_txt << "> " << price << "\n";
    output_txt << "\n";
}