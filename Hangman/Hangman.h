#pragma once
#include <iostream>
#include <string>
#include "HangmanQuizTable.h"

class Hangman
{
public:
	Hangman();
	~Hangman();

private:
	int chance; // ��ȸ 5��
	HangmanQuizTable<std::string> random; // ������ϴ� ����
	std::string quiz_result; // ������ϴ� ������ �޾Ƽ� ����, ���߿� ��� �����ؼ��� ���
	std::string underLineOrAlphabet; // �����̶� ���ؼ� "_" �Ǵ� ���ĺ����� �����ֱ� ���� ����
	char inputAlphabet; // �÷��̾ �Է��� ���ĺ�
	std::string wrongAnswerList; // ������ �޾Ƽ� �����ϰ� �����ֱ�����

public:

	void drawLine();
	void UpdateWrongAnswerList(char input);
	void printBoard();
	void CheckInput();
	void printResultMessage();
	void StartHangman();
};

