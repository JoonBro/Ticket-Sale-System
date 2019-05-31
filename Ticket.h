#ifndef TICKET
#define TICKET

#include <iostream>
#include <string>

class Ticket 
{
private:
	int ticketType;//판매티켓 혹은 구매티켓
	std::string ticketHomeTeam;//홈팀
	std::string ticketAwayTeam;//어웨이팀
	std::string ticketTime;//야구경기날짜및시간 //함수에서 시간 parsing 필요
	std::string ticketSeat;//좌석위치
	bool ticketAuction;//auction티켓여부
	bool ticketSold;//판매되었는지 여부
	int ticketPrice;//티켓가격
	int ticketBidPrice;//낙찰가격(auction 시)
	//BidCollection ticketBidList;//티켓에 해당하는 bidList

public:
};

#endif