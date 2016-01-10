#include "Timeup.h"

using RC = util::ResolutionConverter;


const Vec2 Timeup::m_FONT_CENTER_POSITION = {50.0, 50.0};
const double Timeup::m_FONT_SIZE = 20.0;

Timeup::Timeup(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_font(RC::toY(m_FONT_SIZE), Typeface::Heavy, FontStyle::Outline)
	, m_easing(255.0, 0.0, Easing::Expo, 2000)
{
	m_font.changeOutlineStyle(TextOutlineStyle(Color(L"#222222"), Color(L"#EEEEEE"), 3.0));
}

Timeup& Timeup::operator=(const Timeup& obj)
{
	this->m_sceneChanger = obj.m_sceneChanger;
	this->m_easing = obj.m_easing;
	this->m_alpha = obj.m_alpha;
	return *this;
}

void Timeup::start()
{
	m_easing.start();
}

void Timeup::update()
{
	m_alpha = static_cast<uint32>(m_easing.easeIn());
	if(m_easing.isEnd()) {
		m_sceneChanger->reserveNextScene(QuizState::COMMENTARY);
	}
}

void Timeup::draw() const
{
	m_font.drawCenter(L"TIME UP", RC::toVec2(m_FONT_CENTER_POSITION), Color(Color(L"#EEEEEE"), m_alpha));
}