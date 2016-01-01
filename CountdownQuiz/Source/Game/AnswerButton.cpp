#include "AnswerButton.h"


using RC = util::ResolutionConverter;

const double AnswerButton::m_FONT_SIZE = 3.5;
const Vec2 AnswerButton::m_BUTTON_SIZE = {20.0, 20.0};

AnswerButton::AnswerButton(String answerText, bool isCorrect, Vec2 position)
	: m_answerText(answerText)
	, m_isCorrect(isCorrect)
	, m_centerPosition(position)
	, m_answerTextFont(RC::toY(m_FONT_SIZE))
{
	m_nowButtonColor = Color(Palette::White, 255);
	m_button = RoundRect(RectF(RC::toVec2(m_BUTTON_SIZE)), 10.0).setCenter(RC::toVec2(m_centerPosition));
}

AnswerButton& AnswerButton::operator=(const AnswerButton& obj)
{
	this->m_nowButtonColor = obj.m_nowButtonColor;
	this->m_button = obj.m_button;
	this->m_isCorrect = obj.m_isCorrect;
	return *this;
}


void AnswerButton::update()
{
	m_nowButtonColor = m_button.mouseOver ? Color(L"#DDDDDD") : Color(L"#EEEEEE");
}

void AnswerButton::draw() const
{
	m_button.drawShadow({RC::toX(0.4), RC::toX(0.4)}, RC::toX(1.0), RC::toX(0.2));
	m_button.draw(m_nowButtonColor).drawFrame(0.0, 3.0, Color(L"#222222"));
	m_answerTextFont(m_answerText).drawCenter(RC::toVec2(m_centerPosition), Color(L"#222222"));
}

bool AnswerButton::checkClicked() const
{
	return m_button.leftClicked;
}

bool AnswerButton::isCorrect() const
{
	return m_isCorrect;
}