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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="limitTime_ms"> ��������(ms) </param>
	Countdown(uint32 limitTime_ms);
	~Countdown() = default;
public:
	/// <summary>
	/// �J�E���g�_�E���̍X�V������
	/// </summary>
	/// <param name="elapsedTime_ms"> �o�ߎ���(ms) </param>
	void update(uint32 elapsedTime_ms);

	/// <summary>
	/// �J�E���g�_�E���\����`�悷��
	/// </summary>
	void draw() const;
};

