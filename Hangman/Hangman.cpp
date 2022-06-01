#include "Hangman.h"
#include "HangmanQuizTable.h"
#include <iostream>
#include <string>

Hangman::Hangman()
	: chance(5)
{
}
// default�� ���Լ� ���ڴٰ� �����س��� ������cpp�����ο��� ���� �ٽ� ���� �ʿ� ����
/*
Hangman::~Hangman()
{
}
*/
void Hangman::SetUnderLine()
{
	underLineOrAlphabet.clear();

	for (int i = 0; i < 5; ++i)
	{
		underLineOrAlphabet += "_";
	}
}

void Hangman::UpdateWrongAnswerList(char input)
{
	wrongAnswerList += input;
}

void Hangman::PrintBoard()
{
	system("cls");
	std::cout << "���� ��ȸ : " << chance << "\n" << std::endl;
	std::cout << underLineOrAlphabet << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "���� ��� : " << wrongAnswerList << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "�Է��ϼ��� : ";
}

void Hangman::CheckInput()
{
	//int TrueOrFalse = 0; 
	bool bIsCorrectAlphabet = false;

	//�Է¹޴� inputAlphabet�� ���⼭ Ȯ���� �� �ֵ���. ã�� ����ϱ�
	char inputAlphabet;
	std::cin >> inputAlphabet;

	for (int i = 0; i < 5; ++i) // 5 >> wordLength >>> ���߿� Ȥ�� �ٸ� �������� ����� �ϰ� ���� �� ���� �ٲٱ� ����
	{
		if (quizAnswer[i] == inputAlphabet)
		{
			underLineOrAlphabet[i] = inputAlphabet;
			//bTrueOrFalse = true;
			bIsCorrectAlphabet = true;
		}
	}
	
	if (bIsCorrectAlphabet == false)
	{
		UpdateWrongAnswerList(inputAlphabet);
		chance -= 1;
	}
}

void Hangman::PrintResultMessage()
{
	if (chance == 0)
	{
		std::cout << "\n" << "��ȸ�� ���� ����Ͽ����ϴ�. ������ " << quizAnswer << "�����ϴ�." << std::endl;
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
	//random.SetQuizTable();
	random.Build();

	//random�̶� �������� �׳� quiztable�ص� �ɰŸ�???
	//quiz_result = random.getRandomQuiz(); // �������� ���� ������ ��������
	quizAnswer = random.SelectRandomWord(); //

	// DrawLine(); >> PrintBoard������ �־��
	// DrawLine�϶� ���� ���ʿ� �ǵ��ߴ� ���� underOrAlphabet�̶�� ������ü�� "_"�� �־���� ���߿� �񱳹ٲٱ����� �׷����ǵ�,
	// �̸��� �Լ������ ���� �ʾҴ�. ���� DrawLine�ϸ� cout���� ����� �����ϴµ�, �̰� �׳� ���� �̸� �����س��� �Լ�����.
	SetUnderLine();
	PrintBoard();

	while (true)
	{
		//std::cin >> inputAlphabet;
		CheckInput();
		PrintBoard(); // �� ȭ�� ���

		if (chance == 0) // ���� ���� ���� ��
			break;
		else if (quizAnswer == underLineOrAlphabet) // ���� ��������� ���� �������� �ٲٴµ� �������� ��
			break;
	}
	PrintResultMessage();

}
