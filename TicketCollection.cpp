#include "TicketCollection.h"
#include "Timer.h"
#include <algorithm>

TicketCollection *TicketCollection::ticketCollection = NULL;

TicketCollection::TicketCollection() {}

TicketCollection *TicketCollection::getInstance(void)
{
	if (ticketCollection == NULL)
		ticketCollection = new TicketCollection();

	return ticketCollection;
}

void TicketCollection::addTicket(Member *m, int ticketPrice, std::string ticketDate, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction)
{
	Timer *timer = Timer::getInstance();
	//std::cout << m->getId() << " " << timer->getTime() << " " << ticketPrice << " " << ticketDate << " " << ticketHomeTeam << " " << ticketAwayTeam << " " << ticketSeat << " " << ticketAuction << "\n";
	Ticket *ticket = new Ticket(m, timer->getTime(), ticketPrice, ticketDate, ticketHomeTeam, ticketAwayTeam, ticketSeat, ticketAuction);
	ticketList.push_back(ticket);
}

void TicketCollection::transitionToAuction(std::string id, int price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat)
{
	for (int i = 0; i<ticketList.size(); i++)
		if (ticketList[i]->sameTicket(date, homeTeam, awayTeam, seat))
		{
			ticketList[i]->addBidders({ price, id });
			return;
		}
}

void TicketCollection::adjustAuctionTicket(std::string currentTime)
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int curYear = stoi(currentTime.substr(0, 4));
	int curMonth = stoi(currentTime.substr(5, 2));
	int curDay = stoi(currentTime.substr(8, 2));
	int curHour = stoi(currentTime.substr(11, 2));
	int curMinute = stoi(currentTime.substr(14, 2));
	int curSecond = curYear * 365 * 24 * 60 + curMonth * days[curMonth] * 24 * 60 + curDay * 24 * 60 + curHour * 60 + curMinute;

	for (int i = 0; i<ticketList.size(); i++)
	{
		// 경매 등록 안 되어있는 티켓이거나 이미 판매된 티켓이라면 업데이트할 필요 없다.
		if (!ticketList[i]->getTicketAuction() || ticketList[i]->getSoldDate() != "")
			continue;

		std::string time = ticketList[i]->getTicketDate();
		int year = stoi(time.substr(0, 4));
		int month = stoi(time.substr(5, 2));
		int day = stoi(time.substr(8, 2));
		int hour = stoi(time.substr(11, 2));
		int minute = stoi(time.substr(14, 2));
		int second = year * 365 * 24 * 60 + month * days[curMonth] * 24 * 60 + day * 24 * 60 + hour * 60 + minute;

		int diff = curSecond - second;
		if (ticketList[i]->getUnderAuction())
		{
			if (diff > 6 * 60)
				continue;

			std::vector<std::pair<int, std::string>> bidders = ticketList[i]->getBidders();
			if (!bidders.size())
				ticketList[i]->setFailedAuction(true);
			else
			{
				// 오름차순 정렬
				sort(bidders.begin(), bidders.end());
				// 따라서 마지막 티켓이 제일 비싸게 입찰한 멤버
				int idx = bidders.size() - 1;
				ticketList[i]->setTicketPrice(bidders[idx].first);
				ticketList[i]->setBuyerId(bidders[idx].second);
				ticketList[i]->setSoldDate(currentTime);
				ticketList[i]->setReservedDate(currentTime);
			}
		}

		// 경매 시작
		if (diff <= 24 * 60)
			ticketList[i]->setUnderAuction(true);
	}
}

void TicketCollection::deleteExpiredTicket(std::string currentTime)
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int curYear = stoi(currentTime.substr(0, 4));
	int curMonth = stoi(currentTime.substr(5, 2));
	int curDay = stoi(currentTime.substr(8, 2));
	int curHour = stoi(currentTime.substr(11, 2));
	int curMinute = stoi(currentTime.substr(14, 2));
	int curSecond = curYear * 365 * 24 * 60 + curMonth * days[curMonth] * 24 * 60 + curDay * 24 * 60 + curHour * 60 + curMinute;

	int deleteCnt = 0;
	for (int i = 0; i<ticketList.size(); i++)
	{
		std::string time = ticketList[i]->getTicketDate();
		int year = stoi(time.substr(0, 4));
		int month = stoi(time.substr(5, 2));
		int day = stoi(time.substr(8, 2));
		int hour = stoi(time.substr(11, 2));
		int minute = stoi(time.substr(14, 2));
		int second = year * 365 * 24 * 60 + month * days[curMonth] * 24 * 60 + day * 24 * 60 + hour * 60 + minute;

		int diff = curSecond - second;
		// 등록된지 1년 지난 티켓 삭제
		if (diff > 365 * 24 * 60)
			ticketList.erase(ticketList.begin() + (i - deleteCnt++));
	}
}

std::vector<Ticket *> TicketCollection::getSaleTicketList(std::string id)
{
	std::vector<Ticket *> result;
	for (int i = 0; i<ticketList.size(); i++)
	{
		if (ticketList[i]->getSellerId() == id)
			result.push_back(ticketList[i]);
	}
	result = sortTicketList(result);
	return result;
}

std::vector<Ticket *> TicketCollection::getReservedTicketList(std::string id)
{
	std::vector<Ticket *> result;
	for (int i = 0; i<ticketList.size(); i++)
	{
		if (ticketList[i]->getBuyerId() == id)
			result.push_back(ticketList[i]);
	}

	result = sortTicketList(result);
	return result;
}

std::vector<Ticket *> TicketCollection::getAvailableTicketList(std::string homeTeam)
{
	std::vector<Ticket *> result;
	for (int i = 0; i<ticketList.size(); i++)
	{
		std::string team = ticketList[i]->getTicketHomeTeam();
		if (team == homeTeam && !ticketList[i]->getUnderAuction())
			result.push_back(ticketList[i]);
	}

	result = sortTicketList(result);
	return result;
}

std::vector<Ticket *> TicketCollection::getAuctionTicketList(std::string team)
{
	std::vector<Ticket *> result;
	for (int i = 0; i<ticketList.size(); i++)
	{
		std::string home = ticketList[i]->getTicketHomeTeam();
		if (team == home && ticketList[i]->getUnderAuction())
			result.push_back(ticketList[i]);
	}

	result = sortTicketList(result);
	return result;
}

std::vector<Ticket *> TicketCollection::sortTicketList(std::vector<Ticket *> ticketList)
{
	// 시간 기준 버블 소트
	for (int i = 0; i<ticketList.size() - 1; i++)
		for (int j = i + 1; j<ticketList.size(); j++)
		{
			std::string time = ticketList[i]->getTicketDate();
			std::string time2 = ticketList[i]->getTicketDate();

			int year = stoi(time.substr(0, 4));
			int year2 = stoi(time2.substr(0, 4));
			int month = stoi(time.substr(5, 2));
			int month2 = stoi(time.substr(5, 2));
			int day = stoi(time.substr(8, 2));
			int day2 = stoi(time.substr(8, 2));
			int hour = stoi(time.substr(11, 2));
			int hour2 = stoi(time.substr(11, 2));
			int minute = stoi(time.substr(14, 2));
			int minute2 = stoi(time.substr(14, 2));

			if (year > year2 || month > month2 || day > day2 || hour > hour2 || minute > minute2)
			{
				Ticket *temp = ticketList[i];
				ticketList[i] = ticketList[j];
				ticketList[j] = temp;
			}
		}

	return ticketList;
}

Ticket *TicketCollection::reserveTicket(std::string id, std::string ticketDate, std::string homeTeam, std::string awayTeam, std::string seat)
{
	Timer *timer = Timer::getInstance();
	for (int i = 0; i < ticketList.size(); i++)
	{
		if (ticketList[i]->sameTicket(ticketDate, homeTeam, awayTeam, seat))
		{
			ticketList[i]->setBuyerId(id);
			ticketList[i]->setSoldDate(timer->getTime());
			ticketList[i]->setReservedDate(timer->getTime());
			return ticketList[i];
		}
	}

	return nullptr;
}