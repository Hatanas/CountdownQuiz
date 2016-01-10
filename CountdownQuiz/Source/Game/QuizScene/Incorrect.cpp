#include "Incorrect.h"

using RC = util::ResolutionConverter;


const Vec2 Incorrect::m_CROSS_CENTER_POSITION = {50.0, 50.0};
const Vec2 Incorrect::m_RECT_SIZE = {50.0, 10.0};

Incorrect::Incorrect(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
{
}

void Incorrect::start()
{
	m_timer.start();
}

void Incorrect::update()
{
	double normTime = util::Math::norm(m_timer.elapsed(), 0, 2000);
	m_alpha = -Math::Pow(2.0 * normTime - 1.0, 6.0) + 1.0;
	if(normTime == 1.0) {
		m_sceneChanger->reserveNextScene(QuizState::COMMENTARY);
	}
}

void Incorrect::draw() const
{
	Rect(RC::toVec2(m_RECT_SIZE).asPoint()).setCenter(RC::toVec2(m_CROSS_CENTER_POSITION).asPoint()).rotated(Radians(45.0)).draw(ColorF(Palette::Blue, m_alpha));
	Rect(RC::toVec2(m_RECT_SIZE).asPoint()).setCenter(RC::toVec2(m_CROSS_CENTER_POSITION).asPoint()).rotated(Radians(-45.0)).draw(ColorF(Palette::Blue, m_alpha));
}