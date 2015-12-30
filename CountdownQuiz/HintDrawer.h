#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


/// <summary>
/// �q���g�̕\�����s�����߂̃N���X
/// </summary>
class HintDrawer
{
private:
	const Font m_hintTextFont;
	const String m_hintText;
	const double m_y;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="hint"> �q���g�̃e�L�X�g </param>
	HintDrawer(String hintText);
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

