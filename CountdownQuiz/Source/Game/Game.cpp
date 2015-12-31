#include "Game.h"


const uint32 Game::m_LIMIT_TIME = 10000;

Game::Game()
	: m_bar(m_LIMIT_TIME)
	, m_number(m_LIMIT_TIME)
	, m_hint(L"ヒント1 てすとてきっすとテステス", 29.0)
	, m_answer(L"選択肢1", {17.0, 85.0})
{
}

void Game::init()
{
	Graphics::SetBackground(Color(L"#EEEEEE"));
	m_timer.start();
}

void Game::update()
{
	int elapsed = m_timer.elapsed();
	if(elapsed > m_LIMIT_TIME) {
		m_timer.pause();
	}
	m_bar.update(elapsed);
	m_number.update(elapsed);
	m_hint.update();
	m_answer.update();
}

void Game::draw() const
{
	m_bar.draw();
	m_number.draw();
	m_hint.draw();
	m_answer.draw();
}