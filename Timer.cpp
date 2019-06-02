#include "Timer.h"
#include "MemberCollection.h"
#include "TicketCollection.h"

Timer *Timer::timer = NULL;

Timer::Timer() {}

// singleton pattern
Timer *Timer::getInstance(void)
{
	if (timer == NULL)
		timer = new Timer();

	return timer;
}

std::string Timer::getTime(void)
{
	return this->time;
}

void Timer::setTime(std::string time)
{
	this->time = time;
	// ��� ��� Ƽ�� ������Ʈ
	TicketCollection *ticketCollection = TicketCollection::getInstance();
	ticketCollection->adjustAuctionTicket(time);
	ticketCollection->deleteExpiredTicket(time);
}