#ifndef BIDCOLLECTION
#define BIDCOLLECTION

#include <queue>
#include "Bid.h"

class BidCollection {
private:
	std::priority_queue<Bid> bidParticipantList;
public:
};

#endif