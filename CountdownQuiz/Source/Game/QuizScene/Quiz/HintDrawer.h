#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/ResolutionConverter.h"
#include "../../../Utility/Math.h"


/// <summary>
/// �q���g�̕\�����s�����߂̃N���X
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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="hint"> �q���g�̃e�L�X�g </param>
	/// <param name="positionY"> y���W�l(%) </param>
	HintDrawer(String hintText, double positionY);
	~HintDrawer() = default;
	HintDrawer& operator=(const HintDrawer& obj);
public:
	/// <summary>
	/// �X�V������
	/// </summary>
	void update();

	/// <summary>
	/// �q���g�̕`�������
	/// </summary>
	void draw() const;
};

