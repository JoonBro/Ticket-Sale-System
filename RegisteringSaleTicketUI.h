#pragma once

#include <string>

class RegisteringSaleTicketUI
{
public:
	RegisteringSaleTicketUI();
	void sendTicketInfo(std::string price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat, std::string option);
};
