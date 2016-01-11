#include "Commentary.h"

using RC = util::ResolutionConverter;




Commentary::Commentary(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_easingBackground(0.0, 0.5, Easing::Expo, 1000)
	, m_backgroundAlpha(0.0)
	, m_button()
{
}


void Commentary::start()
{
	m_button.start();
	m_easingBackground.start();
}

void Commentary::update()
{
	m_button.update();
	m_backgroundAlpha = m_easingBackground.easeOut();
	if(m_button.isClicked()) {
		m_sceneChanger->reserveNextScene(QuizState::NEXT);
	}
}

void Commentary::draw() const
{
	Rect(RC::toVec2({100.0, 100.0}).asPoint()).setCenter(RC::toVec2({50.0, 50.0}).asPoint()).draw(ColorF(Color(L"#000000"), m_backgroundAlpha));
	m_button.draw();
	Println(m_button.isClicked());
}