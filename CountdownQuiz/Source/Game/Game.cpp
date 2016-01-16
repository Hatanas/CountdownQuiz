#include "Game.h"


Game::Game()
{
}

void Game::init()
{
	m_data->m_questionData.push_back({1, {L"ヒント1", L"ひんと2", L"Hint3", L"大ヒント4"}, {L"ハズレ", L"不正解", L"残念"}, L"正解"});
	m_data->m_questionData.push_back({2, {L"ヒント1", L"ひんと2", L"Hint3", L"大ヒント4"}, {L"ハズレ", L"不正解", L"残念"}, L"正解"});
	m_data->m_questionData.push_back({3, {L"ヒント1", L"ひんと2", L"Hint3", L"大ヒント4"}, {L"ハズレ", L"不正解", L"残念"}, L"正解"});

	std::for_each(m_data->m_questionData.begin(), m_data->m_questionData.end(), [this](const QuestionData &data) {
		m_quizScenes.push_back(data);
	});
	m_quizScenes.front().init();
}

void Game::updateFadeIn(double t) {
	update();
}

void Game::update()
{
	if(m_quizScenes.front().isSwitchNextQuiz()) {
		m_quizScenes.pop_front();
		if(m_quizScenes.empty()) {
			assert(!"GameSceneが終了しました");
			return;
		}
		m_quizScenes.front().init();
	}
	m_quizScenes.front().update();
}

void Game::draw() const
{
	m_quizScenes.front().draw();
}