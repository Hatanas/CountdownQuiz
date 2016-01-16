#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "QuestionData.h"
#include "GameData.h"
#include "QuizScene/QuizScene.h"


class Game : public SceneManager<String, GameData>::Scene
{
private:
	std::list<QuizScene> m_quizScenes;
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
	/// シーンのフェードイン時の更新処理をする．
	/// tが1.0になった時に最初のクイズをスタートする．
	/// </summary>
	void updateFadeIn(double t) override;

	/// <summary>
	/// 描画する．
	/// </summary>
	void draw() const override;
};