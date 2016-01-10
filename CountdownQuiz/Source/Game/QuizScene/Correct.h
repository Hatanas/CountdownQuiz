#pragma once

#include <Siv3D.hpp>
#include "SubScene.h"
#include "SubSceneManager.h"
#include "../../Utility/Math.h"
#include "../../Utility/ResolutionConverter.h"


class Correct : public SubScene
{
private:
	static const Vec2 m_CIRCLE_POSITION;
	static const double m_CIRCLE_RADIUS;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	TimerMillisec m_timer;
	double m_alpha;
public:
	Correct(std::shared_ptr<SubSceneManager> sceneChanger);
	~Correct() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
};

