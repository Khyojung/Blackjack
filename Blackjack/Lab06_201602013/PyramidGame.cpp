#include "stdafx.h"
#include "PyramidGame.h"
#include <ctime>
#include <iostream>

using namespace std;

//Contructor
PyramidGame::PyramidGame(){
	setPlayer(new Player());
	_deck = new Deck();
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			pyramidCard[i][j] = NULL;
		}
	}
	setBet(0);
	score = 0;
}
PyramidGame::~PyramidGame(){
	getPlayer()->~Player();
	_deck->~Deck();
//	delete _player;
//	delete _dealer;
}

//public method
void PyramidGame::startGame(){
	//제일 먼저 쓸 돈을 정한다.
	getPlayer()->setMoney(1);

	//본격 게임을 시작한다.
	while( ask() ){
		cout << "===========================================================" << endl;
		cout << "★★★PyramidGAME START★★★" << endl;
		cout << "===========================================================" << endl;

		cout << endl;
		cout << "★★★GOOD LUCK★★★" << endl;
		cout << endl;

		//초반 카드를 섞는다. setting
		setCards();
		int mineCardNumber = 0;

		do{
			if(mineCardNumber <= 0)
				mineCardNumber = 0;
			//카드를 출력한다.
			cout << "\n\n" << "SCORE : " << score << endl;
			printPyramid();
			cout << "\n" << "OpenCard : ";
			printCard(getPlayer()->getHand()->getCard(mineCardNumber));
			cout << "\n" << endl;

			char newMine;
			cout << ">> 새로운 카드를 뒤집겠습니까?(y or n) : ";
			cin >>  newMine;
			while(newMine == 'y' && mineCardNumber < getPlayer()->getHand()->getSize()-1){
				mineCardNumber++;
				printCard(getPlayer()->getHand()->getCard(mineCardNumber));
				cout << "\n" << endl;
				cout << ">> 새로운 카드를 뒤집겠습니까? : ";
				cin >>  newMine;
			}

			int num = 0;
			cout << ">> 뽑는 카드가 몇장입니까?(1 or 2): ";
			cin >> num;
			if(num == 2){
				int row1;
				int col1;
				int row2;
				int col2;
				cout << ">> 뽑을 카드를 고르세요 (본인의 카드를 고를 경우 행 : 0, 열 : 0)\n";
				cout << "1번째 행 : ";
				cin >> row1;
				cout << "1번째 열 : ";
				cin >> col1;
				cout << "2번째 행 : ";
				cin >> row2;
				cout << "2번째 열 : ";
				cin >> col2;

				if(possibleCard(row1, col1) && possibleCard(row2, col2)){
					if(row1 == 0 && col1 == 0){
						if(count13(getPlayer()->getHand()->getCard(mineCardNumber), pyramidCard[row2][col2])){		
							getPlayer()->getHand()->removeCard(mineCardNumber);
							mineCardNumber--;
							pyramidCard[row2][col2] = NULL;
							score+=10;
						}
						else
							cout << "not add count 13\n" << endl;
					}
					else if(row2 == 0 && col2 == 0){
						if(count13(pyramidCard[row1][col1], getPlayer()->getHand()->getCard(mineCardNumber))){
							pyramidCard[row1][col1] = NULL;
							getPlayer()->getHand()->removeCard(mineCardNumber);
							mineCardNumber--;
							score+=10;
						}
						else
							cout << "not add count 13\n" << endl;
					}
					else{
						if(count13(pyramidCard[row1][col1], pyramidCard[row2][col2])){
							pyramidCard[row1][col1] = NULL;
							pyramidCard[row2][col2] = NULL;
							score+=10;
						}
						else{
							cout << "not add count 13\n" << endl;
						}
					}
				}
				else
					cout << "You Can't\n" << endl;
			}
			else{
				int row1;
				int col1;
				cout << ">> 뽑을 카드를 고르세요 (본인의 카드를 고를 경우 행 : 0, 열 : 0)\n";
				cout << "1번째 행 : ";
				cin >> row1;
				cout << "1번째 열 : ";
				cin >> col1;

				if(possibleCard(row1, col1)){
					if(row1 == 0 && col1 == 0){
						if(count13(getPlayer()->getHand()->getCard(mineCardNumber), NULL)){		
							getPlayer()->getHand()->removeCard(mineCardNumber);
							mineCardNumber--;
							score+=10;
						}
						else
							cout << "not add count 13\n" << endl;
					}
					else{
						if(count13(pyramidCard[row1][col1], NULL)){
							pyramidCard[row1][col1] = NULL;
							score+=10;
						}
						else{
							cout << "not add count 13\n" << endl;
						}
					}
				}
				else
					cout << "You Can't\n" << endl;
			}
		}while(pyramidCard[1][1] != NULL && mineCardNumber < getPlayer()->getHand()->getSize()-1);

		cout << "Your Score : " << score <<  endl;
		clear();
		cout << "===========================================================\n\n" << endl;
	}
}

//private method
void PyramidGame::setCards(){
	for(int pyramidSettingHigh = 1; pyramidSettingHigh <= 7; pyramidSettingHigh++){
		for(int pyramidSettingWide = 1; pyramidSettingWide <= pyramidSettingHigh; pyramidSettingWide++){
			pyramidCard[pyramidSettingHigh][pyramidSettingWide] = _deck->giveCard();
		}
	}
	for(int pack = 0; pack < 24; pack++){
		getPlayer()->getHand()->addCard(_deck->giveCard());
	}
}
void PyramidGame::printPyramid(){
	for(int pyramidSettingHigh = 1; pyramidSettingHigh <= 7; pyramidSettingHigh++){
		for(int i = 7; i > pyramidSettingHigh; i--)
			cout << "    ";
		for(int pyramidSettingWide = 1; pyramidSettingWide <= pyramidSettingHigh; pyramidSettingWide++){
			if(pyramidCard[pyramidSettingHigh][pyramidSettingWide] == NULL){
				cout << "        ";
			}else{
				printCard(pyramidCard[pyramidSettingHigh][pyramidSettingWide]);
			}
		}
		cout << "\n";
	}
}
void PyramidGame::printCard(Card* aCard){
	switch(aCard->getShapeNumber()){
	case 0 :
		cout << "♠";
		break;
	case 1 :
		cout << "♥";
		break;
	case 2 :
		cout << "♣";
		break;
	case 3 :
		cout << "◆";
		break;
	} 
	//숫자를 출력한다.
	//A J Q K를 고려한다.
	switch(aCard->getValue()){
	case 1:
		cout << "A" << "    ";
		break;
	case 11:
		cout << "J" << "    ";
		break;
	case 12:
		cout << "Q" << "    ";
		break;
	case 13:
		cout << "K" << "    ";
		break;
	default:
		cout << aCard->getValue() << "    ";
	}
}
bool PyramidGame::possibleCard(int row, int col){
	if(row == 0 && col == 0){
		return true;
	}
	else if(row == 0 || col == 0){
		return false;
	}
	else if(row > 7 || col > row){
		return false;
	}
	else if(pyramidCard[row][col] == NULL){
		return false;
	}
	else{
		if(pyramidCard[row+1][col] == NULL && pyramidCard[row+1][col+1] == NULL){
			return true;
		}
		return false;
	}
}
bool PyramidGame::count13(Card* firstCard, Card* secondCard){
	if(firstCard->getValue() == 13 && secondCard == NULL)
		return true;
	else if(secondCard != NULL && firstCard->getValue() + secondCard->getValue() == 13)
		return true;
	return false;
}
void PyramidGame::countMoneyWin(){
}
void PyramidGame::countMoneyLose(){
}
void PyramidGame::countMoneyCompare(){
}

void PyramidGame::clear(){
	getPlayer()->getHand()->clear();
	_deck->~Deck();
	_deck = new Deck();
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			pyramidCard[i][j] = NULL;
		}
	}
}