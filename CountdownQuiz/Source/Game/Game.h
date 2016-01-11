#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "QuizScene/QuizScene.h"


class Game : public SceneManager<String>::Scene
{
private:
	std::list<QuizScene> m_quizScenes;
public:
	Game();
	~Game() = default;
public:
	/// <summary>
	/// ����������D
	/// </summary>
	void init() override;

	/// <summary>
	/// �X�V����D
	/// </summary>
	void update() override;

	/// <summary>
	/// �`�悷��D
	/// </summary>
	void draw() const override;
};