#include "CountdownNumber.h"


using RC = util::ResolutionConverter;

const Vec2 CountdownNumber::m_CENTER_POSITION = {10.0, 15.0};
const double CountdownNumber::m_FONT_SIZE = 6.0;
const double CountdownNumber::m_CIRCLE_RADIUS = 10.0;


CountdownNumber::CountdownNumber(uint32 limitTime_ms)
	: m_countNumberFont(RC::toY(m_FONT_SIZE))
	, m_limitTime_ms(limitTime_ms)
	, m_remainingTime_s(0)
{
}


void CountdownNumber::update(uint32 elapsedTime_ms)
{
	// 経過時間を正規化して残り時間を計算
	double t = util::Math::norm(elapsedTime_ms, 0.0, m_limitTime_ms);
	m_remainingTime_s = static_cast<uint32>(EaseInOut(static_cast<double>(util::Time::millisecToSec(m_limitTime_ms)), 0.0, Easing::Linear, t));
}

void CountdownNumber::draw() const
{
	m_countNumberFont(m_remainingTime_s).drawCenter(RC::toVec2(m_CENTER_POSITION));
}