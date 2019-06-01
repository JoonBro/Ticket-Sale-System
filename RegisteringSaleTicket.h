#ifndef REGISTERINGSALETICKET
#define REGISTERINGSALETICKET

#include <string>

class RegisteringSaleTicket
{
public:
    RegisteringSaleTicket();
    void registerSaleTicket(std::string price, std::string date, std::string homeTeam, std::string awayTeam, std::string seat, std::string option);
};

#endif