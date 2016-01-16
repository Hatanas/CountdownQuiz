#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/ResolutionConverter.h"
#include "../../../Utility/Math.h"


/// <summary>
/// ヒントの表示を行うためのクラス
/// </summary>
class HintDrawer
{
private:
	static const double m_FONT_SIZE;
private:
	const Font m_hintTextFont;
	const String m_hintText;
	const Vec2 m_centerPosition;
private:
	TimerMillisec m_timer;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="hintText"> ヒントのテキスト </param>
	/// <param name="positionY"> y座標値(%) </param>
	HintDrawer(String hintText, double positionY);
	~HintDrawer() = default;
	HintDrawer& operator=(const HintDrawer& obj);
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

