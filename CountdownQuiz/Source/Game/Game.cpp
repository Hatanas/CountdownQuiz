#include "Game.h"


const uint32 Game::m_LIMIT_TIME = 20000;

Game::Game()
	: m_countdown(m_LIMIT_TIME)
	, m_answer(L"�I����1", {17.0, 85.0})
{
}

void Game::init()
{
	Graphics::SetBackground(Color(L"#EEEEEE"));
	m_timer.setEvent(L"FirstHint", 100);
	m_timer.setEvent(L"SecondHint", 4000);
	m_timer.setEvent(L"ThirdHint", 9000);
	m_timer.setEvent(L"LastHint", 16000);
	m_timer.setEvent(L"TimerStop", m_LIMIT_TIME);
	//m_timer.start();
}

void Game::update()
{
	if(Input::MouseL.clicked) {
		m_timer.start();
	}
	const uint32 elapsedTime = m_timer.update();

	if(m_timer.onTriggered(L"FirstHint")) {
		HintDrawer first(L"�q���g1 �Ă��ƂĂ������ƃe�X�e�X", 27.0);
		m_hints.push_back(first);
	}
	else if(m_timer.onTriggered(L"SecondHint")) {
		HintDrawer second(L"�q���g2 �Ă��ƂĂ������ƃe�X�e�X", 39.0);
		m_hints.push_back(second);
	}
	else if(m_timer.onTriggered(L"ThirdHint")) {
		HintDrawer third(L"�q���g3 �Ă��ƂĂ������ƃe�X�e�X", 51.0);
		m_hints.push_back(third);
	}
	else if(m_timer.onTriggered(L"LastHint")) {
		HintDrawer last(L"�q���g4 �Ă��ƂĂ������ƃe�X�e�X", 63.0);
		m_hints.push_back(last);
	}
	else if(elapsedTime > m_LIMIT_TIME) {
		m_timer.pause();
	}

	m_countdown.update(elapsedTime);
	std::for_each(m_hints.begin(), m_hints.end(), [](HintDrawer& hint) { hint.update(); });
	m_answer.update();
}

void Game::draw() const
{
	m_countdown.draw();
	std::for_each(m_hints.begin(), m_hints.end(), [](const HintDrawer& hint) { hint.draw(); });
	m_answer.draw();
}