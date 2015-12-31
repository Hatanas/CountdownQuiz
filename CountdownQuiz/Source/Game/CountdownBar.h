#pragma once

#include <Siv3D.hpp>
#include "../Utility/ResolutionConverter.h"
#include "../Utility/Time.h"
#include "../Utility/Math.h"


/// <summary>
/// カウントダウンバーに関するクラス
/// </summary>
class CountdownBar
{
private:
	static const Vec2 m_POSITION;
	static const double m_BAR_LENGTH;
	static const double m_BAR_WIDTH;
	static const double m_HSV_BEGIN_ANGLE;
	static const double m_HSV_END_ANGLE;
private:
	const uint32 m_limitTime_ms;
private:
	double m_nowBarLength;
	double m_nowHSVAngle;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="limitTime_ms"> 制限時間(ms) </param>
	CountdownBar(int limitTime_ms);
	~CountdownBar() = default;
	CountdownBar& operator=(CountdownBar& obj);
public:
	/// <summary>
	/// バーの長さを更新する
	/// </summary>
	/// <param name="elapsedTime_ms"> 経過時間(ms) </param>
	void update(int elapsedTime_ms);

	/// <summary>
	/// バーを描画する
	/// </summary>
	void draw() const;
};

