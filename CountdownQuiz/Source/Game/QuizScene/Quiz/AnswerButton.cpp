#include "AnswerButton.h"


using RC = util::ResolutionConverter;

const double AnswerButton::m_FONT_SIZE = 3.5;
const Vec2 AnswerButton::m_BUTTON_SIZE = {20.0, 20.0};

AnswerButton::AnswerButton(String answerText, bool isCorrect, Vec2 position)
	: Button(answerText, m_BUTTON_SIZE, position, m_FONT_SIZE)
	, m_isCorrect(isCorrect)
{
}

bool AnswerButton::isCorrect() const
{
	return m_isCorrect;
}