#include "Ticket.h"
#include "Timer.h"
#include <iostream>
#include <string>

Ticket::Ticket(Member *m, std::string currentTime, int ticketPrice, std::string ticketTime, std::string ticketHomeTeam, std::string ticketAwayTeam, std::string ticketSeat, bool ticketAuction)
{
    this->ticketPrice = ticketPrice;
    this->ticketDate = ticketTime;
    this->ticketHomeTeam = ticketHomeTeam;
    this->ticketAwayTeam = ticketAwayTeam;
    this->ticketSeat = ticketSeat;
    this->ticketAuction = ticketAuction;
    this->underAuction = false;
    this->buyerID = "";
    this->soldDate = "";
    this->reservedDate = "";
    this->uploadedDate = currentTime;
    this->sellerID = m->getId();
}

int Ticket::getTicketPrice(void)
{
    return this->ticketPrice;
}

void Ticket::setTicketPrice(int price)
{
    this->ticketPrice = price;
}

std::string Ticket::getTicketDate(void)
{
    return this->ticketDate;
}

void Ticket::setTicketDate(std::string date)
{
    this->ticketDate = date;
}

std::string Ticket::getTicketHomeTeam(void)
{
    return this->ticketHomeTeam;
}

void Ticket::setTicketHomeTeam(std::string homeTeam)
{
    this->ticketHomeTeam = homeTeam;
}

std::string Ticket::getTicketAwayTeam(void)
{
    return this->ticketAwayTeam;
}

void Ticket::setTicketAwayTeam(std::string awayTeam)
{
    this->ticketAwayTeam = awayTeam;
}

std::string Ticket::getTicketSeat(void)
{
    return this->ticketSeat;
}

void Ticket::setTicketSeat(std::string seat)
{
    this->ticketSeat = seat;
}

bool Ticket::getTicketAuction(void)
{
    return this->ticketAuction;
}

void Ticket::setTicketAuction(bool flag)
{
    this->ticketAuction = flag;
}

bool Ticket::getUnderAuction(void)
{
    return this->underAuction;
}

void Ticket::setUnderAuction(bool flag)
{
    this->underAuction = flag;
}

bool Ticket::getFailedAuction(void)
{
    return this->failedAuction;
}

void Ticket::setFailedAuction(bool flag)
{
    this->failedAuction = flag;
}

std::vector<std::pair<int, std::string>> Ticket::getBidders(void)
{
    return this->bidders;
}

void Ticket::addBidders(std::pair<int, std::string> p)
{
    this->bidders.push_back(p);
}

std::string Ticket::getBuyerId(void)
{
    return this->buyerID;
}

void Ticket::setBuyerId(std::string id)
{
    this->buyerID = id;
}

std::string Ticket::getReservedDate(void)
{
    return this->reservedDate;
}

void Ticket::setReservedDate(std::string date)
{
    this->reservedDate = date;
}

std::string Ticket::getSellerId(void)
{
    return this->sellerID;
}

void Ticket::setSellerId(std::string id)
{
    this->sellerID = id;
}

std::string Ticket::getSoldDate(void)
{
    return this->soldDate;
}

void Ticket::setSoldDate(std::string date)
{
    this->soldDate = date;
}

std::string Ticket::remainingAuctionTime(void)
{
    Timer *timer = Timer::getInstance();
    std::string currentTime = timer->getTime();

    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int curYear = stoi(currentTime.substr(0, 4));
    int curMonth = stoi(currentTime.substr(5, 2));
    int curDay = stoi(currentTime.substr(8, 2));
    int curHour = stoi(currentTime.substr(11, 2));
    int curMinute = stoi(currentTime.substr(14, 2));
    int curSecond = curYear * 365 * 24 * 60 + curMonth * days[curMonth] * 24 * 60 + curDay * 24 * 60 + curHour * 60 + curMinute;

    std::string playTime = this->getTicketDate();
    int year = stoi(playTime.substr(0, 4));
    int month = stoi(playTime.substr(5, 2));
    int day = stoi(playTime.substr(8, 2));
    int hour = stoi(playTime.substr(11, 2));
    int minute = stoi(playTime.substr(14, 2));
    int second = year * 365 * 24 * 60 + month * days[month] * 24 * 60 + day * 24 * 60 + hour * 60 + minute;

    int diff = curSecond - second - 6 * 60; // 경매 6시간 전 종료시간
    std::string result;
    if(diff / 60 < 10)
        result+='0';
    result += std::to_string(diff / 60);
    result += ':';
    if(diff % 60 < 10)
        result+='0';
    result += std::to_string(diff % 60);
    return result;
}

bool Ticket::sameTicket(std::string date, std::string homeTeam, std::string awayTeam, std::string seat)
{
    if(this->getTicketDate() == date && this->getTicketHomeTeam == homeTeam 
        && this->getTicketAwayTeam == awayTeam && this->getTicketSeat == seat)
        return true;
    
    return false;
}