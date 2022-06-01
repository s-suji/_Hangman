#include "Hangman.h"
#include "HangmanQuizTable.h"
#include <iostream>
#include <string>

Hangman::Hangman()
	: chance(5)
{
}
// default로 빈함수 쓰겠다고 선언해놨기 때문에cpp구현부에서 굳이 다시 써줄 필요 없음
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
	std::cout << "남은 기회 : " << chance << "\n" << std::endl;
	std::cout << underLineOrAlphabet << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "오답 목록 : " << wrongAnswerList << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "입력하세요 : ";
}

void Hangman::CheckInput()
{
	//int TrueOrFalse = 0; 
	bool bIsCorrectAlphabet = false;

	//입력받는 inputAlphabet을 여기서 확인할 수 있도록. 찾기 힘드니깐
	char inputAlphabet;
	std::cin >> inputAlphabet;

	for (int i = 0; i < 5; ++i) // 5 >> wordLength >>> 나중에 혹시 다른 사이즈의 행맨을 하고 싶을 때 쉽게 바꾸기 위해
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
		std::cout << "\n" << "기회를 전부 사용하였습니다. 정답은 " << quizAnswer << "였습니다." << std::endl;
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
	//random.SetQuizTable();
	random.Build();

	//random이라 하지말고 그냥 quiztable해도 될거를???
	//quiz_result = random.getRandomQuiz(); // 랜덤으로 뽑은 변수를 저장해줌
	quizAnswer = random.SelectRandomWord(); //

	// DrawLine(); >> PrintBoard안으로 넣어보기
	// DrawLine일때 내가 애초에 의도했던 것은 underOrAlphabet이라는 변수자체에 "_"를 넣어놓고 나중에 비교바꾸기위해 그랬던건데,
	// 이름이 함수내용과 맞지 않았다. 거의 DrawLine하면 cout같은 출력을 예상하는데, 이건 그냥 값이 미리 세팅해놓는 함수였다.
	SetUnderLine();
	PrintBoard();

	while (true)
	{
		//std::cin >> inputAlphabet;
		CheckInput();
		PrintBoard(); // 새 화면 출력

		if (chance == 0) // 찬스 전부 소진 시
			break;
		else if (quizAnswer == underLineOrAlphabet) // 내가 언더라인을 전부 정답으로 바꾸는데 성공했을 때
			break;
	}
	PrintResultMessage();

}
