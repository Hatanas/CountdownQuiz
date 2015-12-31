#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


/// <summary>
/// �q���g�̕\�����s�����߂̃N���X
/// </summary>
class HintDrawer
{
	static const double m_FONT_SIZE;
	static const Vec2 m_TEXT_AREA_SIZE;
private:
	const Font m_hintTextFont;
	const String m_hintText;
	const Vec2 m_centerPosition_px;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="hint"> �q���g�̃e�L�X�g </param>
	HintDrawer(String hintText, double positionY);
	~HintDrawer() = default;
	HintDrawer& operator=(HintDrawer& obj);
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

