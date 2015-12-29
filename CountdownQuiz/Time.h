#pragma once

#include <Siv3D.hpp>


namespace util
{
class Time
{
private:
	Time() = default;
	~Time() = default;
public:
	static uint32 millisecToSec(uint32 time_ms);
	static uint32 secToMillisec(uint32 time_s);
};
}