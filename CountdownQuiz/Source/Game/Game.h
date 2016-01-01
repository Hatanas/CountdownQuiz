#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Quiz.h"


class Game : public SceneManager<String>::Scene
{
private:
	Quiz m_quiz;
public:
	Game();
	~Game() = default;
public:
	void init() override;
	void update() override;
	void draw() const override;
};