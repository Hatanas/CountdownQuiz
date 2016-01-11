#pragma once

#include <Siv3D.hpp>
#include "ResolutionConverter.h"


namespace util
{
class Button
{
protected:
	const String m_text;
	const Vec2 m_size;
	const Font m_font;
protected:
	Vec2 m_centerPosition;
	RoundRect m_body;
	Color m_bodyColor;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="text"> �{�^���̃e�L�X�g </param>
	/// <param name="size"> �{�^���̃T�C�Y(%) </param>
	/// <param name="centerPosition"> �{�^���̒��S�ʒu(%) </param>
	/// <param name="fontSize"> �e�L�X�g�̃T�C�Y(%) </param>
	Button(String text, Vec2 size, Vec2 centerPosition, double fontSize);
	~Button() = default;
	Button& operator=(const Button& obj);
public:
	/// <summaty>
	/// �X�V������D
	/// �I�[�o�[���C�h�\�D
	/// </summaty>
	virtual void update();

	/// <summaty>
	/// �`�������D
	/// </summaty>
	void draw() const;

	/// <summaty>
	/// �{�^�����N���b�N���ꂽ���𒲂ׂ�D
	/// </summaty>
	/// <returns> �N���b�N���ꂽ�� </returns>
	bool isClicked() const;
};
}