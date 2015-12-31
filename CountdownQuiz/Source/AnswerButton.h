#pragma once

#include <Siv3D.hpp>
#include "Utility/ResolutionConverter.h"


/// <summary>
/// 回答の選択肢を表示するためのクラス
/// </summary>
class AnswerButton
{
private:
	static const double m_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
private:
	const Font m_answerTextFont;
	const String m_answerText;
	const Vec2 m_centerPosition;
private:
	Color m_nowButtonColor;
	RoundRect m_button;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="answerText"> 選択肢のテキスト </param>
	/// <param name="position"> 選択肢の中心位置(%) </param>
	AnswerButton(String answerText, Vec2 position);
	~AnswerButton() = default;
	AnswerButton& operator=(AnswerButton& obj);
public:
	/// <summary>
	/// ボタンの更新をする
	/// </summary>
	void update();

	/// <summary>
	/// ボタンの描画をする
	/// </summary>
	void draw() const;
};

