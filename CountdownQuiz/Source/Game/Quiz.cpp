#include "Quiz.h"


const uint32 Quiz::m_LIMIT_TIME = 20000;

Quiz::Quiz()
	: m_countdown(m_LIMIT_TIME)
{
}

Quiz::~Quiz()
{
}


void Quiz::init()
{
	Graphics::SetBackground(Color(L"#EEEEEE"));
	
	m_timer.setEvent(L"FirstHint", 100);
	m_timer.setEvent(L"SecondHint", 5000);
	m_timer.setEvent(L"ThirdHint", 10000);
	m_timer.setEvent(L"LastHint", 17000);
	m_timer.setEvent(L"TimerStop", m_LIMIT_TIME);

	m_answer = {
		AnswerButton(L"Ë–P", false, {17.0, 85.0}),
		AnswerButton(L"–P", true,  {39.0, 85.0}),
		AnswerButton(L"—´–P", false, {61.0, 85.0}),
		AnswerButton(L"—´éˆ", false, {83.0, 85.0})
	};
	std::random_shuffle(m_answer.begin(), m_answer.end());
}

void Quiz::update()
{
	if(Input::MouseL.clicked) { m_timer.start(); }
	const uint32 elapsedTime = m_timer.update();

	manageHint(elapsedTime);
	m_countdown.update(elapsedTime);
	std::for_each(m_hints.begin(), m_hints.end(), [](HintDrawer& hint) { hint.update(); });
	std::for_each(m_answer.begin(), m_answer.end(), [](AnswerButton& answer) { answer.update(); });

	auto clickableItr = std::find_if(m_answer.begin(), m_answer.end(), [](const AnswerButton& answer) { return answer.checkClicked(); });
	if(clickableItr != m_answer.end()) {
		if(clickableItr->isCorrect()) {
			Println(L"³‰ðI");
		}
		else {
			Println(L"Žc”Oc");
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
		m_hints.push_back(HintDrawer(L"1936”N6ŒŽ19“ú i…", 27.0));
	} else if(m_timer.onTriggered(L"SecondHint")) {
		m_hints.push_back(HintDrawer(L"ƒGƒ“ƒKƒm–¦‰«ŠCí", 39.0));
	} else if(m_timer.onTriggered(L"ThirdHint")) {
		m_hints.push_back(HintDrawer(L"‚‘¬‹‹–ûŠÍu‚èv", 51.0));
	} else if(m_timer.onTriggered(L"LastHint")) {
		m_hints.push_back(HintDrawer(L"uŽ„‚Ìì‚Á‚½—‘Ä‚«AH‚×‚è‚ãHv", 63.0));
	} else if(elapsedTime > m_LIMIT_TIME) {
		m_timer.pause();
	}
}