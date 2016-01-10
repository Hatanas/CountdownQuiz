#pragma once

#include <Siv3D.hpp>
#include "SubScene.h"
#include "SubSceneManager.h"
#include "../../Utility/ResolutionConverter.h"


class Timeup : public SubScene
{
private:
	static const Vec2 m_FONT_CENTER_POSITION;
	static const double m_FONT_SIZE;
private:
	const Font m_font;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	EasingController<double> m_easing;
	uint32 m_alpha;
public:
	Timeup(std::shared_ptr<SubSceneManager> sceneChanger);
	~Timeup() = default;
	Timeup& operator=(const Timeup& obj);
public:
	void start() override;
	void update() override;
	void draw() const override;
};

