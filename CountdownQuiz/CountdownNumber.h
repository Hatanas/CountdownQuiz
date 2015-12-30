#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"
#include "Time.h"
#include "Math.h"

/**
 * 残り時間を表示するクラス
 */
class CountdownNumber
{
private:
	/** 中心の位置 */
	static const Vec2 m_CENTER_POSITION;
	/** フォントのサイズ */
	static const unsigned int m_FONT_SIZE;
private:
	/** フォントオブジェクト */
	const Font m_countNumberFont;
	/** 制限時間(ms) */
	const uint32 m_limitTime_ms;
	/** 残り時間 */
	uint32 m_remainingTime;
public:
	/**
	 * コンストラクタ
	 * @param limitTime_ms 制限時間(ms)
	 */
	CountdownNumber(uint32 limitTime_ms);
	~CountdownNumber() = default;
	CountdownNumber& operator=(CountdownNumber& obj);
public:
	/**
	 * 残り時間を更新する
	 * @param elapsedTime_ms 経過時間(ms)
	 */
	void update(uint32 elapsedTime_ms);
	/**
	 * 残り時間を描画する
	 */
	void draw() const;
};

