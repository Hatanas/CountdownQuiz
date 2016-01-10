#include "Commentary.h"

using RC = util::ResolutionConverter;


const double Commentary::m_BUTTON_FONT_SIZE = 3.0;
const Vec2 Commentary::m_BUTTON_SIZE = {20.0, 10.0};
const Vec2 Commentary::m_BUTTON_BEGIN_POSITION = {50.0, -20.0};
const Vec2 Commentary::m_BUTTON_END_POSITION = {50.0, 50.0};

Commentary::Commentary(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_buttonFont(RC::toY(m_BUTTON_FONT_SIZE))
	, m_easingButton(m_BUTTON_BEGIN_POSITION, m_BUTTON_END_POSITION, Easing::Expo, 1000)
	, m_easingBackground(0.0, 0.5, Easing::Expo, 1000)
	, m_backgroundAlpha(0.0)
{
}


void Commentary::start()
{
	m_easingButton.start();
	m_easingBackground.start();
}

void Commentary::update()
{
	m_nowButtonPosition = m_easingButton.easeIn();
	m_backgroundAlpha = m_easingBackground.easeIn();
	if(Input::MouseL.clicked) {
		m_sceneChanger->reserveNextScene(QuizState::NEXT);
	}
}

void Commentary::draw() const
{
	Rect(RC::toVec2({100.0, 100.0}).asPoint()).setCenter(RC::toVec2({50.0, 50.0}).asPoint()).draw(ColorF(Color(L"#000000"), m_backgroundAlpha));
}