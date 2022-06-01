#pragma once
#include <iostream>
#include <string>
#include "HangmanQuizTable.h"

class Hangman
{
public:
	Hangman();
	~Hangman() = default;

private:
	int chance; // 기회 5번
	HangmanQuizTable<std::string> random; // 맞춰야하는 문제
	std::string quizAnswer; // 맞춰야하는 문제를 받아서 저장, 나중에 결과 비교위해서도 사용
	std::string underLineOrAlphabet; // 정답이랑 비교해서 "_" 또는 알파벳으로 보여주기 위한 변수
	//char inputAlphabet; // 플레이어가 입력할 알파벳 //Hangman의 CheckInput()안에서만 쓰이기 때문에 그냥 지역변수처리
	std::string wrongAnswerList; // 오답을 받아서 저장하고 보여주기위함

public:
	void SetUnderLine();
	void UpdateWrongAnswerList(char input);
	void PrintBoard();
	void CheckInput();
	void PrintResultMessage();
	void StartHangman();
};

