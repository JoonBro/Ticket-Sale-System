#pragma once

#include <string>

class Timer
{
private:
	static Timer *timer; // singleton pattern
	std::string time;
public:
	Timer();
	static Timer *getInstance();
	std::string getTime(void);
	void setTime(std::string time);
};