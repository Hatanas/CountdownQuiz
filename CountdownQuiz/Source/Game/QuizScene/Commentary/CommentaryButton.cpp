#include "CommentaryButton.h"

using RC = util::ResolutionConverter;


const double CommentaryButton::m_BUTTON_FONT_SIZE = 5.0;
const Vec2 CommentaryButton::m_BUTTON_SIZE = {20.0, 10.0};
const Vec2 CommentaryButton::m_BUTTON_BEGIN_POSITION = {50.0, -20.0};
const Vec2 CommentaryButton::m_BUTTON_END_POSITION = {50.0, 50.0};

CommentaryButton::CommentaryButton()
	: Button(L"ŽŸ‚Ö", m_BUTTON_SIZE, m_BUTTON_BEGIN_POSITION, m_BUTTON_FONT_SIZE)
	, m_easing(m_BUTTON_BEGIN_POSITION, m_BUTTON_END_POSITION, Easing::Expo, 1000)
{
}


void CommentaryButton::start()
{
	m_easing.start();
}

void CommentaryButton::update()
{
	m_centerPosition = m_easing.easeOut();
	Button::update();
}