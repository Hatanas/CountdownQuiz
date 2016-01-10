#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/ResolutionConverter.h"
#include "../../../Utility/Time.h"
#include "../../../Utility/Math.h"

/// <summary>
/// 残り時間を表示するためのクラス
/// </summary>
class CountdownNumber
{
private:
	static const Vec2 m_CENTER_POSITION;
	static const double m_FONT_SIZE;
	static const double m_CIRCLE_RADIUS;
private:
	const Font m_countNumberFont;
	const uint32 m_limitTime_ms;
private:
	uint32 m_remainingTime_s;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="limitTime_ms"> 制限時間(ms) </summary>
	CountdownNumber(uint32 limitTime_ms);
	~CountdownNumber() = default;
	CountdownNumber& operator=(const CountdownNumber& obj);
public:
	/// <summary>
	/// 残り時間を更新する
	/// </summary>
	/// <param name="elapsedTime_ms"> 経過時間(ms) </summary>
	void update(uint32 elapsedTime_ms);

	/// <summary>
	/// 残り時間を描画する
	/// </summary>
	void draw() const;
};

