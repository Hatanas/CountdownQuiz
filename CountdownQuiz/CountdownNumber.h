#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"
#include "Time.h"
#include "Math.h"

/**
 * �c�莞�Ԃ�\������N���X
 */
class CountdownNumber
{
private:
	/** ���S�̈ʒu */
	static const Vec2 m_CENTER_POSITION;
	/** �t�H���g�̃T�C�Y */
	static const unsigned int m_FONT_SIZE;
private:
	/** �t�H���g�I�u�W�F�N�g */
	const Font m_countNumberFont;
	/** ��������(ms) */
	const uint32 m_limitTime_ms;
	/** �c�莞�� */
	uint32 m_remainingTime;
public:
	/**
	 * �R���X�g���N�^
	 * @param limitTime_ms ��������(ms)
	 */
	CountdownNumber(uint32 limitTime_ms);
	~CountdownNumber() = default;
	CountdownNumber& operator=(CountdownNumber& obj);
public:
	/**
	 * �c�莞�Ԃ��X�V����
	 * @param elapsedTime_ms �o�ߎ���(ms)
	 */
	void update(uint32 elapsedTime_ms);
	/**
	 * �c�莞�Ԃ�`�悷��
	 */
	void draw() const;
};

