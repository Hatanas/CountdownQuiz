#include "CountdownBar.h"


using RC = util::ResolutionConverter;

const Vec2 CountdownBar::m_POSITION = {15.0, 5.0};
const double CountdownBar::m_BAR_LENGTH = 80.0;
const double CountdownBar::m_BAR_WIDTH = 10.0;
const double CountdownBar::m_HSV_BEGIN_ANGLE = 135.0;
const double CountdownBar::m_HSV_END_ANGLE = 0.0;

CountdownBar::CountdownBar(uint32 limitTime_ms)
	: m_limitTime_ms(limitTime_ms)
	, m_nowBarLength(m_BAR_LENGTH)
	, m_nowHSVAngle(m_HSV_BEGIN_ANGLE)
{
}

void CountdownBar::update(uint32 elapsedTime_ms)
{
	double t = util::Math::norm(elapsedTime_ms, 0.0, m_limitTime_ms);
	m_nowBarLength = EaseInOut(m_BAR_LENGTH, 0.0, Easing::Linear, t);
	m_nowHSVAngle = EaseInOut(m_HSV_BEGIN_ANGLE, m_HSV_END_ANGLE, Easing::Linear, t);
}

void CountdownBar::draw() const
{
	Rect(RC::toX(m_nowBarLength), RC::toY(m_BAR_WIDTH)).setPos(RC::toVec2(m_POSITION).asPoint()).draw(HSV(m_nowHSVAngle, 1.0, 1.0));
	Rect(RC::toX(m_BAR_LENGTH), RC::toY(m_BAR_WIDTH)).setPos(RC::toVec2(m_POSITION).asPoint()).drawFrame(10.0, 0.0, Color(L"#444444"));
}