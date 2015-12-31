#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "CountdownBar.h"
#include "CountdownNumber.h"
#include "HintDrawer.h"
#include "AnswerButton.h"


class Game : public SceneManager<String>::Scene
{
private:
	static const uint32 m_LIMIT_TIME;
private:
	CountdownBar m_bar;
	CountdownNumber m_number;
	HintDrawer m_hint;
	AnswerButton m_answer;
	TimerMillisec m_timer;
public:
	Game();
	~Game() = default;
public:
	void init() override;
	void update() override;
	void draw() const override;
};