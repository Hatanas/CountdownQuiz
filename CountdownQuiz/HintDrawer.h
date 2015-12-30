#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


/// <summary>
/// ヒントの表示を行うためのクラス
/// </summary>
class HintDrawer
{
private:
	const Font m_hintTextFont;
	const String m_hintText;
	const double m_y;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="hint"> ヒントのテキスト </param>
	HintDrawer(String hintText);
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

