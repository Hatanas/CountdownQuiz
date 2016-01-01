#pragma once

#include <Siv3D.hpp>
#include "Countdown.h"
#include "HintDrawer.h"
#include "AnswerButton.h"


class Quiz
{
private:
	static const uint32 m_LIMIT_TIME;
private:
	Countdown m_countdown;
	std::list<HintDrawer> m_hints;
	std::vector<AnswerButton> m_answer;
	EventTimerMillisec m_timer;
public:
	Quiz();
	~Quiz();
public:
	void init();
	void update();
	void draw() const;
private:
	void manageHint(const uint32 elapsedTime);
};

enum class QuizState
{
	INTRO,
	MAIN,
	RESULT,

};