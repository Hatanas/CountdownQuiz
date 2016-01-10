#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/Button.h"


/// <summary>
/// �񓚂̑I������\�����邽�߂̃N���X
/// </summary>
class AnswerButton : public util::Button
{
private:
	static const double m_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
private:
	bool m_isCorrect;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="answerText"> �I�����̃e�L�X�g </param>
	/// <param name="isCorrect"> �����̑I�������ǂ��� </param>
	/// <param name="position"> �I�����̒��S�ʒu(%) </param>
	AnswerButton(String answerText, bool isCorrect, Vec2 position);
	~AnswerButton() = default;
public:

	/// <summary>
	/// �����������̃{�^�����ǂ�����Ԃ�
	/// </summary>
	/// <returns> �����̃{�^�����ǂ��� </returns>
	bool isCorrect() const;
};

