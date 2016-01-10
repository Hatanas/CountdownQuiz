#pragma once

#include <Siv3D.hpp>
#include "Quiz/Countdown.h"
#include "Quiz/HintDrawer.h"
#include "Quiz/AnswerButton.h"
#include "SubSceneManager.h"
#include "SubScene.h"


class Quiz : public SubScene
{
private:
	static const uint32 m_LIMIT_TIME;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	Countdown m_countdown;
	std::list<HintDrawer> m_hints;
	std::vector<AnswerButton> m_answer;
	EventTimerMillisec m_timer;
	std::vector<Vec2> m_HINT_POSITIONS;
public:
	Quiz(std::shared_ptr<SubSceneManager> sceneChanger);
	~Quiz() = default;
public:
	void start() override;
	void update() override;
	void draw() const override;
private:
	void init();
	void manageHint(const uint32 elapsedTime);
};