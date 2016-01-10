#pragma once

#include <Siv3D.hpp>
#include "SubScene.h"
#include "SubSceneManager.h"
#include "../../Utility/Math.h"
#include "../../Utility/ResolutionConverter.h"


class Incorrect : public SubScene
{
private:
	static const Vec2 m_CROSS_CENTER_POSITION;
	static const Vec2 m_RECT_SIZE;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	TimerMillisec m_timer;
	double m_alpha;
public:
	Incorrect(std::shared_ptr<SubSceneManager> sceneChanger);
	~Incorrect() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
};

