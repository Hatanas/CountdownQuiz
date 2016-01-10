#pragma once

#include <Siv3D.hpp>
#include "CountdownBar.h"
#include "CountdownNumber.h"
#include "../../../Utility/ResolutionConverter.h"


class Countdown
{
private:
	static const double m_CIRCLE_RADIUS;
	static const Vec2 m_CIRCLE_POSITION;
	static const Vec2 m_RECT_SIZE;
	static const Vec2 m_RECT_POSITION;
private:
	CountdownBar m_bar;
	CountdownNumber m_number;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="limitTime_ms"> 制限時間(ms) </param>
	Countdown(uint32 limitTime_ms);
	~Countdown() = default;
public:
	/// <summary>
	/// カウントダウンの更新をする
	/// </summary>
	/// <param name="elapsedTime_ms"> 経過時間(ms) </param>
	void update(uint32 elapsedTime_ms);

	/// <summary>
	/// カウントダウン表示を描画する
	/// </summary>
	void draw() const;
};

