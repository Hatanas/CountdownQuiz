#pragma once

#include <Siv3D.hpp>
#include "SubScene.h"
#include "SubSceneManager.h"
#include "../../Utility/ResolutionConverter.h"


class Commentary : public SubScene
{
private:
	static const double m_BUTTON_FONT_SIZE;
	static const Vec2 m_BUTTON_SIZE;
	static const Vec2 m_BUTTON_BEGIN_POSITION;
	static const Vec2 m_BUTTON_END_POSITION;
private:
	const Font m_buttonFont;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	EasingController<Vec2> m_easingButton;
	EasingController<double> m_easingBackground;
	Vec2 m_nowButtonPosition;
	double m_backgroundAlpha;

public:
	Commentary(std::shared_ptr<SubSceneManager> sceneChanger);
	~Commentary() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
};

