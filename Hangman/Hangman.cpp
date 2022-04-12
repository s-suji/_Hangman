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
	std::cout << "남은 기회 : " << chance << "\n" << std::endl;
	std::cout << underLineOrAlphabet << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "오답 목록 : " << wrongAnswerList << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "입력하세요 : ";
}

void Hangman::CheckInput()
{
	int TrueOrFalse = 0; // 인풋이 정답에 있는지 여부 체크용 지역변수

	for (int i = 0; i < 5; ++i)
	{
		// 정답이 있는 경우
		if (quiz_result[i] == inputAlphabet)
		{
			underLineOrAlphabet[i] = inputAlphabet;
			TrueOrFalse = true;
		}
	}
	// 정답이 없는 경우
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
		std::cout << "\n" << "기회를 전부 사용하였습니다. 정답은 " << quiz_result << "였습니다." << std::endl;
		std::cout << "게임을 종료합니다." << std::endl;
	}

	if (chance > 1)
	{
		std::cout << "\n" << "정답을 맞추셨습니다." << "\n" << "게임을 종료합니다." << std::endl;
	}
}

void Hangman::StartHangman()
{
	//퀴즈테이블 세팅, 퀴즈 하나 랜덤으로 받아오기
	random.SetQuizTable();
	quiz_result = random.getRandomQuiz(); // 랜덤으로 뽑은 변수를 저장해줌
	drawLine();
	printBoard();

	while (true)
	{
		std::cin >> inputAlphabet;
		CheckInput();
		system("cls");
		printBoard(); // 새 화면 출력

		if (chance == 0) // 찬스 전부 소진 시
			break;
		else if (quiz_result == underLineOrAlphabet) // 내가 언더라인을 전부 정답으로 바꾸는데 성공했을 때
			break;
	}
	printResultMessage();

}
