#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "QuizScene/QuizScene.h"
#include "QuizScene/Quiz.h"
#include "QuizScene/QuestionNumberDrawer.h"


class Game : public SceneManager<String>::Scene
{
private:
	QuizScene m_sceneChanger;
public:
	Game();
	~Game() = default;
public:
	/// <summary>
	/// 初期化する．
	/// </summary>
	void init() override;

	/// <summary>
	/// 更新する．
	/// </summary>
	void update() override;

	/// <summary>
	/// 描画する．
	/// </summary>
	void draw() const override;
};