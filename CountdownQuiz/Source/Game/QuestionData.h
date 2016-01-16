#pragma once

#include <Siv3D.hpp>


struct QuestionData
{
public:
	int m_questionNumber;
	std::vector<String> m_hints;
	std::vector<String> m_incorrectAnswers;
	String m_correctAnswer;
};