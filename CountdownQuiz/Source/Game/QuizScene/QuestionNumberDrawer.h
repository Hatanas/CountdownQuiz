#pragma once

#include <Siv3D.hpp>
#include "../../Utility/ResolutionConverter.h"
#include "../../Utility/Math.h"
#include "SubSceneManager.h"
#include "SubScene.h"


class QuestionNumberDrawer : public SubScene
{
private:
	static const Vec2 m_RECT_SIZE;
	static const Vec2 m_BACKGROUND_SIZE;
	static const double m_FONT_SIZE;
private:
	const Font m_questionNumberFont;
private:
	std::shared_ptr<SubSceneManager> m_sceneChanger;
	Vec2 m_rectCenterPosition;
	Vec2 m_backgroundCenterPosition;
	double m_fontAlpha;
	TimerMillisec m_timer;
	String m_questionNumber;
	bool m_isBlind;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="sceneChanger"> �V�[���؂�ւ��p�I�u�W�F�N�g </param>
	/// <param name="questionNumber"> ���ԍ� </param>
	QuestionNumberDrawer(std::shared_ptr<SubSceneManager> sceneChanger, int questionNumber);
	~QuestionNumberDrawer() = default;
	QuestionNumberDrawer& operator=(const QuestionNumberDrawer& obj);
public:
	void start() override;
	void update() override;
	void draw() const override;
};

