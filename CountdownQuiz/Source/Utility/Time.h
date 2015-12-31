#pragma once

#include <Siv3D.hpp>


namespace util
{
/// <summary>
/// ©ì‚ÌŠÔ‚ÉŠÖ‚·‚éŠÖ”ŒQ
/// </summary>
class Time
{
private:
	Time() = default;
	~Time() = default;
public:
	/// <summary>
	/// ƒ~ƒŠ•b(ms)‚ğ•b(s)‚É•ÏŠ·‚·‚é
	/// </summary>
	/// <param name="time_ms"> ŠÔ(ƒ~ƒŠ•b) </param>
	/// <returns> ŠÔ(•b) </returns>
	static uint32 millisecToSec(uint32 time_ms);

	/// <summary>
	/// •b(s)‚ğƒ~ƒŠ•b(ms)‚É•ÏŠ·‚·‚é
	/// </summary>
	/// <param name="time_s"> ŠÔ(•b) </param>
	/// <returns> ŠÔ(ƒ~ƒŠ•b) </returns>
	static uint32 secToMillisec(uint32 time_s);
};
}