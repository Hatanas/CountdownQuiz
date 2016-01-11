#pragma once

#include <Siv3D.hpp>
#include "../../../Utility/Button.h"


class CommentaryButton : public util::Button
{
private:
	static const double m_BUTTON_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
	static const Vec2 m_BUTTON_BEGIN_POSITION;
	static const Vec2 m_BUTTON_END_POSITION;
private:
	EasingController<Vec2> m_easing;
public:
	CommentaryButton();
	~CommentaryButton() = default;
public:
	/// <summaty>
	/// �A�j���[�V�������X�^�[�g������D
	/// </summaty>
	void start();
	void update() override;
};

