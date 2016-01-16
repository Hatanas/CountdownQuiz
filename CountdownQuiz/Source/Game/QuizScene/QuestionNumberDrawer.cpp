#include "QuestionNumberDrawer.h"


using RC = util::ResolutionConverter;

const Vec2 QuestionNumberDrawer::m_RECT_SIZE = {100.0, 30.0};
const Vec2 QuestionNumberDrawer::m_BACKGROUND_SIZE = {100.0, 100.0};
const double QuestionNumberDrawer::m_FONT_SIZE = 6.0;

QuestionNumberDrawer::QuestionNumberDrawer(std::shared_ptr<SubSceneManager> sceneChanger, int questionNumber)
	: m_sceneChanger(sceneChanger)
	, m_questionNumberFont(RC::toY(m_FONT_SIZE))
	, m_rectCenterPosition({160.0, 50.0})
	, m_backgroundCenterPosition({-60.0, 50.0})
	, m_isBlind(true)
{
	m_questionNumber = std::to_wstring(questionNumber) + L"–â–Ú";
}

QuestionNumberDrawer& QuestionNumberDrawer::operator=(const QuestionNumberDrawer& obj)
{
	this->m_rectCenterPosition = obj.m_rectCenterPosition;
	this->m_backgroundCenterPosition = obj.m_backgroundCenterPosition;
	this->m_fontAlpha = obj.m_fontAlpha;
	this->m_timer = obj.m_timer;
	this->m_questionNumber = obj.m_questionNumber;
	return *this;
}


void QuestionNumberDrawer::start()
{
	m_timer.start();
}

void QuestionNumberDrawer::update()
{
	double normTime = util::Math::norm(m_timer.ms(), 0, 2000);
	double normPosition = (1.0 / 2.0) * (Math::Pow(2.0 * normTime - 1.0, 5.0) + 1.0);
	
	m_rectCenterPosition = {util::Math::inverseNorm(normPosition, 0.0, 200.0) - 50.0, 50.0};
	m_backgroundCenterPosition = {util::Math::inverseNorm(1.0 - normPosition, 0.0, 200.0) - 50.0, 50.0};
	m_fontAlpha = -Math::Pow(2.0 * normTime - 1.0, 4.0) + 1.0;
	m_isBlind = normTime < 0.5;

	if(normTime == 1.0) {
		m_timer.reset();
		m_sceneChanger->reserveNextScene(QuizState::MAIN);
	}
}

void QuestionNumberDrawer::draw() const
{
	if(m_isBlind) {
		Rect(RC::toVec2({0.0, 0.0}).asPoint(), RC::toVec2(m_BACKGROUND_SIZE).asPoint()).draw(Color(L"#EEEEEE"));
	}
	Rect(RC::toVec2(m_BACKGROUND_SIZE).asPoint()).setCenter(RC::toVec2(m_backgroundCenterPosition).asPoint()).draw(Color(L"#AAAAAA"));
	Rect(RC::toVec2(m_RECT_SIZE).asPoint()).setCenter(RC::toVec2(m_rectCenterPosition).asPoint()).draw(Color(L"#EEEEEE"));
	m_questionNumberFont(m_questionNumber).drawCenter(RC::toVec2({50.0, 50.0}), ColorF(util::Math::norm(34, 0, 255), m_fontAlpha));
}