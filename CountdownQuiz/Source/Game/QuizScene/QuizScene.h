#pragma once

#include "SubSceneManager.h"
#include "QuestionNumberDrawer.h"
#include "Quiz.h"
#include "SubScene.h"
#include "Correct.h"
#include "Incorrect.h"
#include "Timeup.h"
#include "Commentary.h"
#include "NextDummy.h"


class QuizScene
{
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	std::shared_ptr<SubScene> m_nowScene;
	std::shared_ptr<QuestionNumberDrawer> m_questionNumDrawer;
	std::shared_ptr<Quiz> m_quizScene;
	std::shared_ptr<Correct> m_correct;
	std::shared_ptr<Incorrect> m_incorrect;
	std::shared_ptr<Timeup> m_timeup;
	std::shared_ptr<Commentary> m_commentary;
	std::shared_ptr<NextDummy> m_nextDummy;
public:
	QuizScene();
	~QuizScene() = default;
public:
	/// <summary>
	/// �V�[�����X�V����D
	/// </summary>
	void update();

	/// <summary>
	/// �V�[����`�悷��D
	/// </summary>
	void draw() const;

	/// <summary>
	/// ���̃N�C�Y�Ɉڍs���邩�ǂ���
	/// </summary>
	/// <returns> ���ɐi�ނ� </returns>
	bool isSwitchNextQuiz() const;
private:
	void init();
	void changeProcess();
};

