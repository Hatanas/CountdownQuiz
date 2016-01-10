#include "QuizScene.h"


QuizScene::QuizScene()
{
	m_sceneChanger = std::make_shared<SubSceneManager>(QuizState::INTRO);
	m_questionNumDrawer = std::make_shared<QuestionNumberDrawer>(m_sceneChanger, 1);
	m_quizScene = std::make_shared<Quiz>(m_sceneChanger);
	m_correct = std::make_shared<Correct>(m_sceneChanger);
	m_incorrect = std::make_shared<Incorrect>(m_sceneChanger);
	m_timeup = std::make_shared<Timeup>(m_sceneChanger);
	m_commentary = std::make_shared<Commentary>(m_sceneChanger);
	m_nextDummy = std::make_shared<NextDummy>(m_sceneChanger);
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

bool QuizScene::isSwitchNextQuiz() const
{
	return m_sceneChanger->getNowScene() == QuizState::NEXT;
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
		case QuizState::TIMEUP:
			m_nowScene = m_timeup;
			break;
		case QuizState::COMMENTARY:
			m_nowScene = m_commentary;
			break;
		case QuizState::NEXT:
			m_nowScene = m_nextDummy;
			break;
		default:
			assert(!"ë∂ç›ÇµÇ»Ç¢SceneÇ™åƒÇ—èoÇ≥ÇÍÇ‹ÇµÇΩ");
			break;
	}
}