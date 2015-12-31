#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


/// <summary>
/// ヒントの表示を行うためのクラス
/// </summary>
class HintDrawer
{
	static const double m_FONT_SIZE;
	static const Vec2 m_TEXT_AREA_SIZE;
private:
	const Font m_hintTextFont;
	const String m_hintText;
	const Vec2 m_centerPosition_px;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="hint"> ヒントのテキスト </param>
	HintDrawer(String hintText, double positionY);
	~HintDrawer() = default;
	HintDrawer& operator=(HintDrawer& obj);
public:
	/// <summary>
	/// 更新をする
	/// </summary>
	void update();

	/// <summary>
	/// ヒントの描画をする
	/// </summary>
	void draw() const;
};

