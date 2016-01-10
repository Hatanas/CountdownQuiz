#pragma once

#include "SubSceneManager.h"
#include "QuestionNumberDrawer.h"
#include "Quiz.h"
#include "SubScene.h"
#include "Correct.h"
#include "Incorrect.h"


class QuizScene
{
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	std::shared_ptr<SubScene> m_nowScene;
	std::shared_ptr<QuestionNumberDrawer> m_questionNumDrawer;
	std::shared_ptr<Quiz> m_quizScene;
	std::shared_ptr<Correct> m_correct;
	std::shared_ptr<Incorrect> m_incorrect;
public:
	QuizScene();
	~QuizScene() = default;
public:
	/// <summary>
	/// シーンを更新する．
	/// </summary>
	void update();

	/// <summary>
	/// シーンを描画する．
	/// </summary>
	void draw() const;
private:
	void init();
	void changeProcess();
};

