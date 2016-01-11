#pragma once

#include "SubSceneManager.h"
#include "QuestionNumberDrawer.h"
#include "Quiz/Quiz.h"
#include "SubScene.h"
#include "Correct.h"
#include "Incorrect.h"
#include "Timeup.h"
#include "Commentary/Commentary.h"
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
	/// 初期化する．
	/// 次のクイズに移行する際に呼び出す．
	/// </summary>
	void init();

	/// <summary>
	/// シーンを更新する．
	/// </summary>
	void update();

	/// <summary>
	/// シーンを描画する．
	/// </summary>
	void draw() const;

	/// <summary>
	/// 次のクイズに移行するかどうか
	/// </summary>
	/// <returns> 次に進むか </returns>
	bool isSwitchNextQuiz() const;
private:
	void changeProcess();
};

