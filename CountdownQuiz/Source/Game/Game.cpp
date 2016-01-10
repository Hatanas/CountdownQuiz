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
}

void Game::draw() const
{
	m_sceneChanger.draw();
}