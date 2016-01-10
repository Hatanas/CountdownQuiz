#include "Correct.h"

using RC = util::ResolutionConverter;


const Vec2 Correct::m_CIRCLE_POSITION = {50.0, 50.0};
const double Correct::m_CIRCLE_RADIUS = 30.0;

Correct::Correct(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_easing(1.0, 0.0, Easing::Expo, 2000)
{
}

void Correct::start()
{
	m_easing.start();
}

void Correct::update()
{
	m_alpha = m_easing.easeIn();
	if(m_easing.isEnd()) {
		m_sceneChanger->reserveNextScene(QuizState::COMMENTARY);
	}
}

void Correct::draw() const
{
	Circle(RC::toVec2(m_CIRCLE_POSITION), RC::toY(m_CIRCLE_RADIUS)).drawFrame(RC::toY(10.0), 0.0, ColorF(Palette::Red, m_alpha));
}