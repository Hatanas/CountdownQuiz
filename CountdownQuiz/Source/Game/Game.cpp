#include "Game.h"


Game::Game()
	: m_quiz()
{
}

void Game::init()
{
	m_quiz.init();
}

void Game::update()
{
	m_quiz.update();
}

void Game::draw() const
{
	m_quiz.draw();
}