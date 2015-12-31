#include "CountdownNumber.h"


using RC = util::ResolutionConverter;

const Vec2 CountdownNumber::m_CENTER_POSITION = {10.0, 15.0};
const double CountdownNumber::m_FONT_SIZE = 5.0;
const double CountdownNumber::m_CIRCLE_RADIUS = 10.0;


CountdownNumber::CountdownNumber(uint32 limitTime_ms)
	: m_countNumberFont(RC::toY(m_FONT_SIZE))
	, m_limitTime_ms(limitTime_ms)
	, m_remainingTime(0)
{
}

CountdownNumber& CountdownNumber::operator=(CountdownNumber& obj)
{
	this->m_remainingTime = obj.m_remainingTime;
	return *this;
}


void CountdownNumber::update(uint32 elapsedTime_ms)
{
	// Œo‰ßŠÔ‚ğ³‹K‰»‚µ‚Äc‚èŠÔ‚ğŒvZ
	double t = util::Math::norm(elapsedTime_ms, 0.0, m_limitTime_ms);
	m_remainingTime = static_cast<uint32>(EaseInOut(static_cast<double>(util::Time::millisecToSec(m_limitTime_ms)), 0.0, Easing::Linear, t));
}

void CountdownNumber::draw() const
{
	m_countNumberFont(m_remainingTime).drawCenter(RC::toVec2(m_CENTER_POSITION));
}