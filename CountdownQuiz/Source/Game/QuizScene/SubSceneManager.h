#pragma once


enum class QuizState
{
	INTRO,
	MAIN,
	CORRECT,
	INCORRECT,
	TIMEUP,
	COMMENTARY,
	NEXT,

	NONE
};

class SubSceneManager
{
	QuizState m_nowScene;
	QuizState m_nextScene;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="initialScene"> 最初のシーン </param>
	SubSceneManager(QuizState initialScene);
	~SubSceneManager() = default;
public:
	/// <summary>
	/// 次のシーンを予約する．
	/// シーンを変えたいタイミングで，次のシーンを指定して呼び出す．
	/// </summary>
	/// <param name="nextScene"> 次のシーン </param>
	void reserveNextScene(QuizState nextScene);

	/// <summary>
	/// シーンを切り替える．
	/// 実際にシーン切り替え処理を行うときに呼び出す．
	/// </summary>
	void changeScene();

	/// <summary>
	/// 次のシーンを取得する．
	/// </summary>
	/// <returns> 次のシーン </returns>
	QuizState getNextScene() const;

	/// <summary>
	/// 現在のシーンを取得する．
	/// </summary>
	/// <returns> 現在のシーン </returns>
	QuizState getNowScene() const;
};

