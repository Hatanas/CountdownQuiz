#include "Quiz.h"


const uint32 Quiz::m_LIMIT_TIME = 20000;


Quiz::Quiz(std::shared_ptr<SubSceneManager> sceneChanger)
	: m_sceneChanger(sceneChanger)
	, m_countdown(m_LIMIT_TIME)
{
	m_HINT_POSITIONS.push_back({17.0, 85.0});
	m_HINT_POSITIONS.push_back({39.0, 85.0});
	m_HINT_POSITIONS.push_back({61.0, 85.0});
	m_HINT_POSITIONS.push_back({83.0, 85.0});
	init();
}


void Quiz::init()
{
	m_timer.setEvent(L"FirstHint", 100);
	m_timer.setEvent(L"SecondHint", 5000);
	m_timer.setEvent(L"ThirdHint", 10000);
	m_timer.setEvent(L"LastHint", 17000);
	m_timer.setEvent(L"TimerStop", m_LIMIT_TIME);

	Shuffle(m_HINT_POSITIONS);

	m_answer = {
		AnswerButton(L"選択肢1", false, m_HINT_POSITIONS[0]),
		AnswerButton(L"選択肢2", true,  m_HINT_POSITIONS[1]),
		AnswerButton(L"選択肢3", false, m_HINT_POSITIONS[2]),
		AnswerButton(L"選択肢4", false, m_HINT_POSITIONS[3])
	};
}

void Quiz::start()
{
	m_timer.start();
}

void Quiz::update()
{
	const uint32 elapsedTime = m_timer.update();

	manageHint(elapsedTime);
	m_countdown.update(elapsedTime);
	std::for_each(m_hints.begin(), m_hints.end(), [](HintDrawer& hint) { hint.update(); });
	std::for_each(m_answer.begin(), m_answer.end(), [](AnswerButton& answer) { answer.update(); });

	auto clickableItr = std::find_if(m_answer.begin(), m_answer.end(), [](const AnswerButton& answer) { return answer.isClicked(); });
	if(clickableItr != m_answer.end()) {
		if(clickableItr->isCorrect()) {
			Println(L"正解！");
			m_sceneChanger->reserveNextScene(QuizState::CORRECT);
		}
		else {
			Println(L"残念…");
			m_sceneChanger->reserveNextScene(QuizState::INCORRECT);
		}
	}
}

void Quiz::draw() const
{
	m_countdown.draw();
	std::for_each(m_hints.begin(), m_hints.end(), [](const HintDrawer& hint) { hint.draw(); });
	std::for_each(m_answer.begin(), m_answer.end(), [](const AnswerButton& answer) { answer.draw(); });
}


void Quiz::manageHint(const uint32 elapsedTime)
{
	if(m_timer.onTriggered(L"FirstHint")) {
		m_hints.push_back(HintDrawer(L"ヒント1ひんと1Hint1", 27.0));
	} else if(m_timer.onTriggered(L"SecondHint")) {
		m_hints.push_back(HintDrawer(L"ヒント2ひんと2Hint2", 39.0));
	} else if(m_timer.onTriggered(L"ThirdHint")) {
		m_hints.push_back(HintDrawer(L"ヒント3ひんと3Hint3", 51.0));
	} else if(m_timer.onTriggered(L"LastHint")) {
		m_hints.push_back(HintDrawer(L"ヒント4ひんと4Hint4", 63.0));
	} else if(elapsedTime > m_LIMIT_TIME) {
		m_timer.pause();
		m_sceneChanger->reserveNextScene(QuizState::TIMEUP);
	}
}