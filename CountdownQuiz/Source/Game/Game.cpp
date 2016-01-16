#include "Game.h"


Game::Game()
{
}

void Game::init()
{
	m_data->m_questionData.push_back({1, {L"�q���g1", L"�Ђ��2", L"Hint3", L"��q���g4"}, {L"�n�Y��", L"�s����", L"�c�O"}, L"����"});
	m_data->m_questionData.push_back({2, {L"�q���g1", L"�Ђ��2", L"Hint3", L"��q���g4"}, {L"�n�Y��", L"�s����", L"�c�O"}, L"����"});
	m_data->m_questionData.push_back({3, {L"�q���g1", L"�Ђ��2", L"Hint3", L"��q���g4"}, {L"�n�Y��", L"�s����", L"�c�O"}, L"����"});

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
			assert(!"GameScene���I�����܂���");
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