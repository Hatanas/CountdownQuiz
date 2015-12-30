#pragma once

#include <Siv3D.hpp>


namespace util
{
/// <summary>
/// 自作の時間に関する関数群
/// </summary>
class Time
{
private:
	Time() = default;
	~Time() = default;
public:
	/// <summary>
	/// ミリ秒(ms)を秒(s)に変換する
	/// </summary>
	/// <param name="time_ms"> 時間(ミリ秒) </param>
	/// <returns> 時間(秒) </returns>
	static uint32 millisecToSec(uint32 time_ms);

	/// <summary>
	/// 秒(s)をミリ秒(ms)に変換する
	/// </summary>
	/// <param name="time_s"> 時間(秒) </param>
	/// <returns> 時間(ミリ秒) </returns>
	static uint32 secToMillisec(uint32 time_s);
};
}