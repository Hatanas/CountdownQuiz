#pragma once

#include <Siv3D.hpp>
#include "../Utility/ResolutionConverter.h"
#include "../Utility/Time.h"
#include "../Utility/Math.h"

/// <summary>
/// �c�莞�Ԃ�\�����邽�߂̃N���X
/// </summary>
class CountdownNumber : Uncopyable
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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="limitTime_ms"> ��������(ms) </summary>
	CountdownNumber(uint32 limitTime_ms);
	~CountdownNumber() = default;
public:
	/// <summary>
	/// �c�莞�Ԃ��X�V����
	/// </summary>
	/// <param name="elapsedTime_ms"> �o�ߎ���(ms) </summary>
	void update(uint32 elapsedTime_ms);

	/// <summary>
	/// �c�莞�Ԃ�`�悷��
	/// </summary>
	void draw() const;
};

