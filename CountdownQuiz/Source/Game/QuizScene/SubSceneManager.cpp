#include "SubSceneManager.h"


SubSceneManager::SubSceneManager(QuizState initialScene)
	: m_nowScene(initialScene)
	, m_nextScene(QuizState::NONE)
{
}


void SubSceneManager::reserveNextScene(QuizState nextScene)
{
	m_nextScene = nextScene;
}

void SubSceneManager::changeScene()
{
	m_nowScene = m_nextScene;
	m_nextScene = QuizState::NONE;
}

QuizState SubSceneManager::getNextScene() const
{
	return m_nextScene;
}

QuizState SubSceneManager::getNowScene() const
{
	return m_nowScene;
}