#ifndef SEARCHTICKETUI
#define SEARCHTICKETUI

#include "TicketCollection.h"
#include <string>

class SearchTicketUI
{
private:
    static std::string homeTeam;
public:
    SearchTicketUI();
    std::string getHomeTeam(void);
    void setHomeTeam(std::string team);
    void selectTeam(void);
    void reserveTicket(void);
};

#endif