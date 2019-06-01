#ifndef SEARCHAUCTIONTICKETUI
#define SEARCHAUCITONTICKEtUI

#include <string>

class SearchAuctionTicketUI
{
private:
    static std::string homeTeam;
public:
    SearchAuctionTicketUI();
    std::string getHomeTeam(void);
    void setHomeTeam(std::string team);
    void selectTeam(void);
    void bidForAuction(void);
};

#endif