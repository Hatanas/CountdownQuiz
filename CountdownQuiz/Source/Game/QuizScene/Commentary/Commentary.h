#pragma once

#include <Siv3D.hpp>
#include "../SubScene.h"
#include "../SubSceneManager.h"
#include "../../../Utility/ResolutionConverter.h"
#include "CommentaryButton.h"


class Commentary : public SubScene
{
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	EasingController<double> m_easingBackground;
	EasingController<double> m_easingFadeOut;
	double m_backgroundAlpha;
	double m_fadeOutAlpha;
	CommentaryButton m_button;
public:
	Commentary(std::shared_ptr<SubSceneManager> sceneChanger);
	~Commentary() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
};

