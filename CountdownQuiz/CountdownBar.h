#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"
#include "Time.h"
#include "Math.h"


class CountdownBar
{
private:
	static const int BAR_LENGTH_;
	static const int BAR_HEIGHT_;
	static const double HSV_BEGIN_ANGLE_;
	static const double HSV_END_ANGLE_;
private:
	const int limitTime_ms_;
	const Font fontOfCountNumber_;
	int nowBarLength_;
	int nowLimitTime_s_;
	double nowHSVAngle_;
public:
	CountdownBar(int limitTime_ms);
	~CountdownBar() = default;
	CountdownBar& operator=(CountdownBar& obj);
public:
	void update(int elapsedTime_ms);
	void draw() const;
};

