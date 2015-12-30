#include "Time.h"


uint32 util::Time::millisecToSec(uint32 time_ms)
{
	return time_ms / 1000;
}

uint32 util::Time::secToMillisec(uint32 time_m)
{
	return time_m * 1000;
}