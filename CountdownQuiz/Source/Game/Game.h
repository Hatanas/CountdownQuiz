#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <list>
#include <algorithm>
#include "Countdown.h"
#include "HintDrawer.h"
#include "AnswerButton.h"


class Game : public SceneManager<String>::Scene
{
private:
	static const uint32 m_LIMIT_TIME;
private:
	Countdown m_countdown;
	std::list<HintDrawer> m_hints;
	AnswerButton m_answer;
	EventTimerMillisec m_timer;
public:
	Game();
	~Game() = default;
public:
	void init() override;
	void update() override;
	void draw() const override;
};