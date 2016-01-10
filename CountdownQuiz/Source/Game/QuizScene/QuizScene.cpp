#include "QuizScene.h"


QuizScene::QuizScene()
{
	m_sceneChanger = std::make_shared<SubSceneManager>(QuizState::INTRO);
	m_questionNumDrawer = std::make_shared<QuestionNumberDrawer>(m_sceneChanger, 1);
	m_quizScene = std::make_shared<Quiz>(m_sceneChanger);
	m_correct = std::make_shared<Correct>(m_sceneChanger);
	m_incorrect = std::make_shared<Incorrect>(m_sceneChanger);
	init();
}


void QuizScene::update()
{
	if(m_sceneChanger->getNextScene() != QuizState::NONE) {
		m_sceneChanger->changeScene();
		changeProcess();
		m_nowScene->start();
	}
	m_nowScene->update();
}

void QuizScene::draw() const
{
	if(m_sceneChanger->getNowScene() != QuizState::MAIN) {
		m_quizScene->draw();
	}
	m_nowScene->draw();
}

void QuizScene::init()
{
	changeProcess();
	m_nowScene->start();
}

void QuizScene::changeProcess()
{
	switch(m_sceneChanger->getNowScene()) {
		case QuizState::INTRO:
			m_nowScene = m_questionNumDrawer;
			break;
		case QuizState::MAIN:
			m_nowScene = m_quizScene;
			break;
		case QuizState::CORRECT:
			m_nowScene = m_correct;
			break;
		case QuizState::INCORRECT:
			m_nowScene = m_incorrect;
			break;
		default:
			assert(!"ë∂ç›ÇµÇ»Ç¢SceneÇ™åƒÇ—èoÇ≥ÇÍÇ‹ÇµÇΩ");
			break;
	}
}