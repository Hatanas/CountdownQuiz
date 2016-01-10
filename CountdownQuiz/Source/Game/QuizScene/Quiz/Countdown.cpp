#include "Countdown.h"


using RC = util::ResolutionConverter;

const double Countdown::m_CIRCLE_RADIUS = 10.15;
const Vec2 Countdown::m_CIRCLE_POSITION = {10.0, 15.0};
const Vec2 Countdown::m_RECT_SIZE = {85.0, 10.0};
const Vec2 Countdown::m_RECT_POSITION = {10.0, 5.0};

Countdown::Countdown(uint32 limitTime_ms)
	: m_bar(limitTime_ms)
	, m_number(limitTime_ms)
{
}

void Countdown::update(uint32 elapsedTime_ms)
{
	m_bar.update(elapsedTime_ms);
	m_number.update(elapsedTime_ms);
}

void Countdown::draw() const
{
	Circle(RC::toVec2(m_CIRCLE_POSITION), RC::toY(m_CIRCLE_RADIUS)).draw(Color(L"#222222"));
	Rect(RC::toVec2(m_RECT_POSITION).asPoint(), RC::toVec2(m_RECT_SIZE).asPoint()).draw(Color(L"#222222"));
	m_bar.draw();
	m_number.draw();
}