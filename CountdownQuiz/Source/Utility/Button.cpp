#include "Button.h"

using RC = util::ResolutionConverter;


util::Button::Button(String text, Vec2 size, Vec2 centerPosition, double fontSize)
	: m_text(text)
	, m_size(size)
	, m_font(RC::toY(fontSize))
	, m_centerPosition(centerPosition)
	, m_body(RectF(RC::toVec2(m_size).asPoint()), 10.0)
	, m_bodyColor(L"#EEEEEE")
{
	m_body.setCenter(RC::toVec2(m_centerPosition));
}

util::Button& util::Button::operator=(const Button& obj)
{
	this->m_centerPosition = obj.m_centerPosition;
	this->m_body = obj.m_body;
	this->m_bodyColor = obj.m_bodyColor;
	return *this;
}


void util::Button::update()
{
	m_bodyColor = m_body.mouseOver ? Color(L"#DDDDDD") : Color(L"#EEEEEE");
	m_body.setCenter(RC::toVec2(m_centerPosition));
}

void util::Button::draw() const
{
	m_body.drawShadow({RC::toX(0.5), RC::toX(0.5)}, RC::toX(1.0), RC::toX(0.2));
	m_body.draw(m_bodyColor).drawFrame(0.0, 3.0, Color(L"#222222"));
	m_font(m_text).drawCenter(RC::toVec2(m_centerPosition), Color(L"#222222"));
}

bool util::Button::isClicked() const
{
	return m_body.leftClicked;
}