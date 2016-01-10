#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


namespace util
{
class Button
{
private:
	const String m_text;
	const Vec2 m_size;
	const Font m_font;
private:
	Vec2 m_centerPosition;
	RoundRect m_body;
	Color m_bodyColor;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="text"> ボタンのテキスト </param>
	/// <param name="size"> ボタンのサイズ(%) </param>
	/// <param name="centerPosition"> ボタンの中心位置(%) </param>
	/// <param name="fontSize"> テキストのサイズ(%) </param>
	Button(String text, Vec2 size, Vec2 centerPosition, double fontSize);
	~Button() = default;
	Button& operator=(const Button& obj);
public:
	/// <summaty>
	/// 更新をする．
	/// </summaty>
	void update();

	/// <summaty>
	/// 描画をする．
	/// </summaty>
	void draw() const;

	/// <summaty>
	/// ボタンがクリックされたかを調べる．
	/// </summaty>
	/// <returns> クリックされたか </returns>
	bool isClicked() const;
};
}