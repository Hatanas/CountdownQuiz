#include "Correct.h"

using RC = util::ResolutionConverter;


const Vec2 Correct::m_CIRCLE_POSITION = {50.0, 50.0};
const double Correct::m_CIRCLE_RADIUS = 30.0;

Correct::Correct(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
{
}

void Correct::start()
{
	m_timer.start();
}

void Correct::update()
{
	double normTime = util::Math::norm(m_timer.elapsed(), 0, 2000);
	m_alpha = -Math::Pow(2.0 * normTime - 1.0, 6.0) + 1.0;
	if(normTime == 1.0) {
		m_sceneChanger->reserveNextScene(QuizState::COMMENTARY);
	}
}

void Correct::draw() const
{
	Circle(RC::toVec2(m_CIRCLE_POSITION), RC::toY(m_CIRCLE_RADIUS)).drawFrame(RC::toY(10.0), 0.0, ColorF(Palette::Red, m_alpha));
}