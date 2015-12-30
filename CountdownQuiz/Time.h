#pragma once

#include <Siv3D.hpp>


namespace util
{
/// <summary>
/// ����̎��ԂɊւ���֐��Q
/// </summary>
class Time
{
private:
	Time() = default;
	~Time() = default;
public:
	/// <summary>
	/// �~���b(ms)��b(s)�ɕϊ�����
	/// </summary>
	/// <param name="time_ms"> ����(�~���b) </param>
	/// <returns> ����(�b) </returns>
	static uint32 millisecToSec(uint32 time_ms);

	/// <summary>
	/// �b(s)���~���b(ms)�ɕϊ�����
	/// </summary>
	/// <param name="time_s"> ����(�b) </param>
	/// <returns> ����(�~���b) </returns>
	static uint32 secToMillisec(uint32 time_s);
};
}