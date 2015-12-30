#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"
#include "Time.h"
#include "Math.h"


class CountdownBar
{
private:
	static const Vec2 m_POSITION;
	static const double m_BAR_LENGTH;
	static const double m_BAR_WIDTH;
	static const double m_HSV_BEGIN_ANGLE;
	static const double m_HSV_END_ANGLE;
private:
	const uint32 m_limitTime_ms;
	double m_nowBarLength;
	double m_nowHSVAngle;
public:
	CountdownBar(int limitTime_ms);
	~CountdownBar() = default;
	CountdownBar& operator=(CountdownBar& obj);
public:
	void update(int elapsedTime_ms);
	void draw() const;
};

