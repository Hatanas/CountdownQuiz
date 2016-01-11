#include "Game.h"


Game::Game()
{
}

void Game::init()
{
	m_quizScenes.push_back(QuizScene());
	m_quizScenes.push_back(QuizScene());
	m_quizScenes.push_back(QuizScene());
	m_quizScenes.front().init();
}

void Game::update()
{
	if(m_quizScenes.front().isSwitchNextQuiz()) {
		m_quizScenes.pop_front();
		if(m_quizScenes.empty()) {
			assert(!"GameSceneÇ™èIóπÇµÇ‹ÇµÇΩ");
			return;
		}
		m_quizScenes.front().init();
	}
	m_quizScenes.front().update();
}

void Game::draw() const
{
	m_quizScenes.front().draw();
}