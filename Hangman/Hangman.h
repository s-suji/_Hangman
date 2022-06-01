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
	int chance; // ��ȸ 5��
	HangmanQuizTable<std::string> random; // ������ϴ� ����
	std::string quizAnswer; // ������ϴ� ������ �޾Ƽ� ����, ���߿� ��� �����ؼ��� ���
	std::string underLineOrAlphabet; // �����̶� ���ؼ� "_" �Ǵ� ���ĺ����� �����ֱ� ���� ����
	//char inputAlphabet; // �÷��̾ �Է��� ���ĺ� //Hangman�� CheckInput()�ȿ����� ���̱� ������ �׳� ��������ó��
	std::string wrongAnswerList; // ������ �޾Ƽ� �����ϰ� �����ֱ�����

public:
	void SetUnderLine();
	void UpdateWrongAnswerList(char input);
	void PrintBoard();
	void CheckInput();
	void PrintResultMessage();
	void StartHangman();
};

