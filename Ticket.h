#pragma once

#include <iostream>
#include <string>
#include "Member.h"

class Ticket
{
private:
	int ticketPrice; // ����
	std::string ticketDate; // �ð�
	std::string ticketHomeTeam; // Ȩ��
	std::string ticketAwayTeam; // �������
	std::string ticketSeat; // �¼�
	bool ticketAuction; // ��� �ɼ�
	bool underAuction; // ���� ��� ���ΰ�
	bool failedAuction; // ���� ����
	std::vector<std::pair<int, std::string>> bidders; // ������ �����
	std::string buyerID; // Ƽ�� ������
	std::string reservedDate; // ������ ��¥
	std::string sellerID; // Ƽ�� �Ǹ���
	std::string soldDate; // �Ǹ��� ��¥
	std::string uploadedDate; // Ƽ���� ����� ��¥
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