#include "Incorrect.h"

using RC = util::ResolutionConverter;


const Vec2 Incorrect::m_CROSS_CENTER_POSITION = {50.0, 50.0};
const Vec2 Incorrect::m_RECT_SIZE = {50.0, 10.0};

Incorrect::Incorrect(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_easing(1.0, 0.0, Easing::Expo, 2000)
{
}

void Incorrect::start()
{
	m_easing.start();
}

void Incorrect::update()
{
	m_alpha = m_easing.easeIn();
	if(m_easing.isEnd()) {
		m_sceneChanger->reserveNextScene(QuizState::COMMENTARY);
	}
}

void Incorrect::draw() const
{
	Rect(RC::toVec2(m_RECT_SIZE).asPoint()).setCenter(RC::toVec2(m_CROSS_CENTER_POSITION).asPoint()).rotated(Radians(45.0)).draw(ColorF(Palette::Blue, m_alpha));
	Rect(RC::toVec2(m_RECT_SIZE).asPoint()).setCenter(RC::toVec2(m_CROSS_CENTER_POSITION).asPoint()).rotated(Radians(-45.0)).draw(ColorF(Palette::Blue, m_alpha));
}