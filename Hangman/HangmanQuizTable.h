#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

template <typename T>
class HangmanQuizTable
{
private:
	std::vector<T> quizTable;

public :
	HangmanQuizTable()
	{

	}
	~HangmanQuizTable()
	{

	}

public:

	//void SetQuizTable()
	//quiztable이 중복이 되고, 아무래도 내가 함수내용을 봤을 때 다른 함수명을 쓰는게 어울려보였다.
	void Build()
	{
		const int Init_Num = 10;
		const std::string str[Init_Num] = { "adult", "basic", "catch", "dream", "exist", "frame", "laugh", "major", "party", "stage" };
		for (int i = 0; i < 10; ++i)
		{
			std::string temp = str[i];
			quizTable.push_back(temp);
		}
	}

	//T getRandomQuiz()
	//이하동문
	T SelectRandomWord()
	{
		srand((unsigned int)time(0));
		int idx = 0;
		idx = rand() % 10;
		return quizTable[idx];
	}
};