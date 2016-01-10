#pragma once

#include <Siv3D.hpp>
#include "SubScene.h"
#include "SubSceneManager.h"
#include "../../Utility/ResolutionConverter.h"


class NextDummy : public SubScene
{
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
public:
	NextDummy(std::shared_ptr<SubSceneManager> sceneChanger);
	~NextDummy() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
};

