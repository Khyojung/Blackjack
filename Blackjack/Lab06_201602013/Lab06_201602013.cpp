// Lab06_201602013.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "BlackjackGame.h"
#include "PyramidGame.h"

using namespace std;

int main()
{
	int chooseGame = 0;
	
	cout << "<< WelCome to casino World!! >>\n\n" << endl;
	cout << ">> Which game will you play?(1.BlackjackGame	2.PiramidGame) : ";
	cin >> chooseGame;

	do{
		if(chooseGame == 1){
			BlackjackGame* _game = new BlackjackGame();
			_game->startGame();
			_game->~BlackjackGame();
		}
		else if(chooseGame == 2){
			PyramidGame* _game = new PyramidGame();
			_game->startGame();
			_game->~PyramidGame();
		}
		cout << ">> Which game will you play?(0.No Game	1.BlackjackGame	2.PiramidGame) : " << endl;
		cin >> chooseGame;
	}while(chooseGame != 0);

	cout << "<< Bye Bye!! >>\n\n" << endl;

	return 0;
}

