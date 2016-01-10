#include "Game.h"


Game::Game()
	: m_sceneChanger()
{
}

void Game::init()
{
}

void Game::update()
{
	m_sceneChanger.update();
	if(m_sceneChanger.isSwitchNextQuiz()) {
		Println(L"Next Quiz");
	}
}

void Game::draw() const
{
	m_sceneChanger.draw();
}