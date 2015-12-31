#include "AnswerButton.h"


using RC = util::ResolutionConverter;

const double AnswerButton::m_FONT_SIZE = 3.5;
const Vec2 AnswerButton::m_BUTTON_SIZE = {20.0, 20.0};

AnswerButton::AnswerButton(String answerText, Vec2 position)
	: m_answerText(answerText)
	, m_centerPosition(position)
	, m_answerTextFont(RC::toY(m_FONT_SIZE))
{
	m_nowButtonColor = Color(Palette::White, 255);
	m_button = RoundRect(RectF(RC::toVec2(m_BUTTON_SIZE)), 10.0).setCenter(RC::toVec2(m_centerPosition));
}

AnswerButton& AnswerButton::operator=(AnswerButton& obj)
{
	obj;
	return *this;
}


void AnswerButton::update()
{
	m_nowButtonColor = m_button.mouseOver ? Color(L"#DDDDDD") : Color(L"#EEEEEE");
}

void AnswerButton::draw() const
{
	m_button.draw(m_nowButtonColor).drawFrame(0.0, 3.0, Color(L"#222222"));
	m_answerTextFont(m_answerText).drawCenter(RC::toVec2(m_centerPosition), Color(L"#222222"));
}