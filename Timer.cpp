#include "Timer.h"
#include "MemberCollection.h"

Timer *Timer::timer = NULL;

Timer::Timer(){}

// singleton pattern
Timer *Timer::getInstance(void)
{
    if(timer == NULL)
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
    // 모든 멤버 티켓 업데이트
    
    
}