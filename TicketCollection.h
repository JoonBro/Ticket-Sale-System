#ifndef TICKETCOLLECTION
#define TICKETCOLLECTION

#include "Ticket.h"
#include <vector>
#include <string>

class TicketCollection 
{
private:
	static TicketCollection *ticketCollection;
	std::vector<Ticket *> ticketList;
public:
	TicketCollection();
	static TicketCollection *getInstance(void);
	void addTicket(Member *m, int ticketPrice, std::string ticketDate, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction);
	void transitionToAuction(std::string id, int price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat);
	void adjustAuctionTicket(std::string currentTime);
	void deleteExpiredTicket(std::string currentTime);
	std::vector<Ticket *> getSaleTicketList(std::string id);
	std::vector<Ticket *> getReservedTicketList(std::string id);
	std::vector<Ticket *> getAvailableTicketList(std::string homeTeam);
	std::vector<Ticket *> getAuctionTicketList(std::string team);
	std::vector<Ticket *> sortTicketList(std::vector<Ticket *> ticketList);
	Ticket *reserveTicket(std::string id, std::string ticketDate, std::string homeTeam, std::string awayTeam, std::string seat);
};

#endif