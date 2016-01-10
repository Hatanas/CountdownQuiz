#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/Button.h"


/// <summary>
/// 回答の選択肢を表示するためのクラス
/// </summary>
class AnswerButton : public util::Button
{
private:
	static const double m_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
private:
	bool m_isCorrect;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="answerText"> 選択肢のテキスト </param>
	/// <param name="isCorrect"> 正解の選択肢かどうか </param>
	/// <param name="position"> 選択肢の中心位置(%) </param>
	AnswerButton(String answerText, bool isCorrect, Vec2 position);
	~AnswerButton() = default;
public:

	/// <summary>
	/// 正しい答えのボタンかどうかを返す
	/// </summary>
	/// <returns> 正解のボタンかどうか </returns>
	bool isCorrect() const;
};

