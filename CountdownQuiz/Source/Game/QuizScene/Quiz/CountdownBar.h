#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/ResolutionConverter.h"
#include "../../../Utility/Time.h"
#include "../../../Utility/Math.h"


/// <summary>
/// �J�E���g�_�E���o�[�Ɋւ���N���X
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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="limitTime_ms"> ��������(ms) </param>
	CountdownBar(uint32 limitTime_ms);
	~CountdownBar() = default;
	CountdownBar& operator=(const CountdownBar& obj);
public:
	/// <summary>
	/// �o�[�̒������X�V����
	/// </summary>
	/// <param name="elapsedTime_ms"> �o�ߎ���(ms) </param>
	void update(uint32 elapsedTime_ms);

	/// <summary>
	/// �o�[��`�悷��
	/// </summary>
	void draw() const;
};

