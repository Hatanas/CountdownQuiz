#pragma once

#include <Siv3D.hpp>
#include "../Utility/ResolutionConverter.h"


/// <summary>
/// �񓚂̑I������\�����邽�߂̃N���X
/// </summary>
class AnswerButton
{
private:
	static const double m_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
private:
	const Font m_answerTextFont;
	const String m_answerText;
	const Vec2 m_centerPosition;
private:
	Color m_nowButtonColor;
	RoundRect m_button;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="answerText"> �I�����̃e�L�X�g </param>
	/// <param name="position"> �I�����̒��S�ʒu(%) </param>
	AnswerButton(String answerText, Vec2 position);
	~AnswerButton() = default;
	AnswerButton& operator=(AnswerButton& obj);
public:
	/// <summary>
	/// �{�^���̍X�V������
	/// </summary>
	void update();

	/// <summary>
	/// �{�^���̕`�������
	/// </summary>
	void draw() const;
};

