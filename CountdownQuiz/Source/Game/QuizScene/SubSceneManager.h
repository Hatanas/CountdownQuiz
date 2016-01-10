#pragma once


enum class QuizState
{
	INTRO,
	MAIN,
	CORRECT,
	INCORRECT,
	COMMENTARY,

	NONE
};

class SubSceneManager
{
	QuizState m_nowScene;
	QuizState m_nextScene;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="initialScene"> �ŏ��̃V�[�� </param>
	SubSceneManager(QuizState initialScene);
	~SubSceneManager() = default;
public:
	/// <summary>
	/// ���̃V�[����\�񂷂�D
	/// �V�[����ς������^�C�~���O�ŁC���̃V�[�����w�肵�ČĂяo���D
	/// </summary>
	/// <param name="nextScene"> ���̃V�[�� </param>
	void reserveNextScene(QuizState nextScene);

	/// <summary>
	/// �V�[����؂�ւ���D
	/// ���ۂɃV�[���؂�ւ��������s���Ƃ��ɌĂяo���D
	/// </summary>
	void changeScene();

	/// <summary>
	/// ���̃V�[�����擾����D
	/// </summary>
	/// <returns> ���̃V�[�� </returns>
	QuizState getNextScene() const;

	/// <summary>
	/// ���݂̃V�[�����擾����D
	/// </summary>
	/// <returns> ���݂̃V�[�� </returns>
	QuizState getNowScene() const;
};

