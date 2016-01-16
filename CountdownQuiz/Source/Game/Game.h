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
	/// ����������D
	/// </summary>
	void init() override;

	/// <summary>
	/// �X�V����D
	/// </summary>
	void update() override;

	/// <summary>
	/// �V�[���̃t�F�[�h�C�����̍X�V����������D
	/// t��1.0�ɂȂ������ɍŏ��̃N�C�Y���X�^�[�g����D
	/// </summary>
	void updateFadeIn(double t) override;

	/// <summary>
	/// �`�悷��D
	/// </summary>
	void draw() const override;
};