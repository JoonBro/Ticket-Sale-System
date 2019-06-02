#pragma once

#include <iostream>
#include <string>
#include "Member.h"

class Ticket
{
private:
	int ticketPrice; // 가격
	std::string ticketDate; // 시간
	std::string ticketHomeTeam; // 홈팀
	std::string ticketAwayTeam; // 어웨이팀
	std::string ticketSeat; // 좌석
	bool ticketAuction; // 경매 옵션
	bool underAuction; // 현재 경매 중인가
	bool failedAuction; // 낙찰 실패
	std::vector<std::pair<int, std::string>> bidders; // 입찰한 사람들
	std::string buyerID; // 티켓 구매자
	std::string reservedDate; // 구매한 날짜
	std::string sellerID; // 티켓 판매자
	std::string soldDate; // 판매한 날짜
	std::string uploadedDate; // 티켓을 등록한 날짜
public:
	Ticket(Member *m, std::string currentTime, int ticketPrice, std::string ticketTime, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction);
	int getTicketPrice(void);
	void setTicketPrice(int price);
	std::string getTicketDate(void);
	void setTicketDate(std::string date);
	std::string getTicketHomeTeam(void);
	void setTicketHomeTeam(std::string homeTeam);
	std::string getTicketAwayTeam(void);
	void setTicketAwayTeam(std::string awayTeam);
	std::string getTicketSeat(void);
	void setTicketSeat(std::string seat);
	bool getTicketAuction(void);
	void setTicketAuction(bool flag);
	bool getUnderAuction(void);
	void setUnderAuction(bool flag);
	bool getFailedAuction(void);
	void setFailedAuction(bool flag);
	std::vector<std::pair<int, std::string>> getBidders(void);
	void addBidders(std::pair<int, std::string> p);
	std::string getBuyerId(void);
	void setBuyerId(std::string id);
	std::string getReservedDate(void);
	void setReservedDate(std::string date);
	std::string getSellerId(void);
	void setSellerId(std::string id);
	std::string getSoldDate(void);
	void setSoldDate(std::string date);
	std::string remainingAuctionTime(void);
	bool sameTicket(std::string date, std::string homeTeam, std::string awayTeam, std::string seat);
};