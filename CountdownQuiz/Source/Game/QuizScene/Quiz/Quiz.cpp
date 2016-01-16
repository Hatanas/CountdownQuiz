#include "Quiz.h"


const Milliseconds Quiz::m_LIMIT_TIME = Milliseconds(20000);


Quiz::Quiz(std::shared_ptr<SubSceneManager> sceneChanger, const QuestionData& questionData)
	: m_sceneChanger(sceneChanger)
	, m_countdown(m_LIMIT_TIME.count())
	, m_HINT_POSITIONS(4)
	, m_questionData(questionData)
{
	m_HINT_POSITIONS[0] = {17.0, 85.0};
	m_HINT_POSITIONS[1] = {39.0, 85.0};
	m_HINT_POSITIONS[2] = {61.0, 85.0};
	m_HINT_POSITIONS[3] = {83.0, 85.0};
	init();
}


void Quiz::init()
{
	m_timer.addEvent(L"FirstHint", 100.0ms);
	m_timer.addEvent(L"SecondHint", 5000.0ms);
	m_timer.addEvent(L"ThirdHint", 10000.0ms);
	m_timer.addEvent(L"LastHint", 17000.0ms);
	m_timer.addEvent(L"TimerStop", m_LIMIT_TIME);

	Shuffle(m_HINT_POSITIONS);

	m_answer = {
		AnswerButton(m_questionData.m_correctAnswer, true,  m_HINT_POSITIONS[0]),
		AnswerButton(m_questionData.m_incorrectAnswers[0], false, m_HINT_POSITIONS[1]),
		AnswerButton(m_questionData.m_incorrectAnswers[1], false, m_HINT_POSITIONS[2]),
		AnswerButton(m_questionData.m_incorrectAnswers[2], false, m_HINT_POSITIONS[3])
	};
}

void Quiz::start()
{
	m_timer.start();
}

void Quiz::update()
{
	const auto elapsedTime = m_timer.update();

	manageHint(elapsedTime);
	m_countdown.update(elapsedTime.count());
	std::for_each(m_hints.begin(), m_hints.end(), [](HintDrawer& hint) { hint.update(); });
	std::for_each(m_answer.begin(), m_answer.end(), [](AnswerButton& answer) { answer.update(); });

	// ‰ñ“šƒ{ƒ^ƒ“‚Ì”»’è
	auto clickableItr = std::find_if(m_answer.begin(), m_answer.end(), [](const AnswerButton& answer) { return answer.isClicked(); });
	if(clickableItr != m_answer.end()) {
		if(clickableItr->isCorrect()) {
			// ³‰ð‚ÌŽž
			m_sceneChanger->reserveNextScene(QuizState::CORRECT);
		}
		else {
			// •s³‰ð‚ÌŽž
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


void Quiz::manageHint(const Milliseconds elapsedTime)
{
	if(m_timer.onTriggered(L"FirstHint")) {
		m_hints.push_back(HintDrawer(m_questionData.m_hints[0], 27.0));
	} else if(m_timer.onTriggered(L"SecondHint")) {
		m_hints.push_back(HintDrawer(m_questionData.m_hints[1], 39.0));
	} else if(m_timer.onTriggered(L"ThirdHint")) {
		m_hints.push_back(HintDrawer(m_questionData.m_hints[2], 51.0));
	} else if(m_timer.onTriggered(L"LastHint")) {
		m_hints.push_back(HintDrawer(m_questionData.m_hints[3], 63.0));
	} else if(elapsedTime > m_LIMIT_TIME) {
		m_timer.pause();
		m_sceneChanger->reserveNextScene(QuizState::TIMEUP);
	}
}