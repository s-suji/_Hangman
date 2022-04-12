#include "Hangman.h"
#include "HangmanQuizTable.h"
#include <iostream>
#include <string>

Hangman::Hangman()
	: chance(5)
	, inputAlphabet(0)
{
}

Hangman::~Hangman()
{
}


void Hangman::drawLine()
{
	for (int i = 0; i < 5; ++i)
	{
		underLineOrAlphabet += "_";
	}
}

void Hangman::UpdateWrongAnswerList(char input)
{
	wrongAnswerList += input;
}

void Hangman::printBoard()
{
	std::cout << "���� ��ȸ : " << chance << "\n" << std::endl;
	std::cout << underLineOrAlphabet << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "���� ��� : " << wrongAnswerList << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "�Է��ϼ��� : ";
}

void Hangman::CheckInput()
{
	int TrueOrFalse = 0; // ��ǲ�� ���信 �ִ��� ���� üũ�� ��������

	for (int i = 0; i < 5; ++i)
	{
		// ������ �ִ� ���
		if (quiz_result[i] == inputAlphabet)
		{
			underLineOrAlphabet[i] = inputAlphabet;
			TrueOrFalse = true;
		}
	}
	// ������ ���� ���
	if (TrueOrFalse == false)
	{
		UpdateWrongAnswerList(inputAlphabet);
		chance -= 1;
	}
}

void Hangman::printResultMessage()
{
	if (chance == 0)
	{
		std::cout << "\n" << "��ȸ�� ���� ����Ͽ����ϴ�. ������ " << quiz_result << "�����ϴ�." << std::endl;
		std::cout << "������ �����մϴ�." << std::endl;
	}

	if (chance > 1)
	{
		std::cout << "\n" << "������ ���߼̽��ϴ�." << "\n" << "������ �����մϴ�." << std::endl;
	}
}

void Hangman::StartHangman()
{
	//�������̺� ����, ���� �ϳ� �������� �޾ƿ���
	random.SetQuizTable();
	quiz_result = random.getRandomQuiz(); // �������� ���� ������ ��������
	drawLine();
	printBoard();

	while (true)
	{
		std::cin >> inputAlphabet;
		CheckInput();
		system("cls");
		printBoard(); // �� ȭ�� ���

		if (chance == 0) // ���� ���� ���� ��
			break;
		else if (quiz_result == underLineOrAlphabet) // ���� ��������� ���� �������� �ٲٴµ� �������� ��
			break;
	}
	printResultMessage();

}
