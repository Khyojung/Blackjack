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
	//���� ���� �� ���� ���Ѵ�.
	getPlayer()->setMoney(1);

	//���� ������ �����Ѵ�.
	while( ask() ){
		cout << "===========================================================" << endl;
		cout << "�ڡڡ�PyramidGAME START�ڡڡ�" << endl;
		cout << "===========================================================" << endl;

		cout << endl;
		cout << "�ڡڡ�GOOD LUCK�ڡڡ�" << endl;
		cout << endl;

		//�ʹ� ī�带 ���´�. setting
		setCards();
		int mineCardNumber = 0;

		do{
			if(mineCardNumber <= 0)
				mineCardNumber = 0;
			//ī�带 ����Ѵ�.
			cout << "\n\n" << "SCORE : " << score << endl;
			printPyramid();
			cout << "\n" << "OpenCard : ";
			printCard(getPlayer()->getHand()->getCard(mineCardNumber));
			cout << "\n" << endl;

			char newMine;
			cout << ">> ���ο� ī�带 �����ڽ��ϱ�?(y or n) : ";
			cin >>  newMine;
			while(newMine == 'y' && mineCardNumber < getPlayer()->getHand()->getSize()-1){
				mineCardNumber++;
				printCard(getPlayer()->getHand()->getCard(mineCardNumber));
				cout << "\n" << endl;
				cout << ">> ���ο� ī�带 �����ڽ��ϱ�? : ";
				cin >>  newMine;
			}

			int num = 0;
			cout << ">> �̴� ī�尡 �����Դϱ�?(1 or 2): ";
			cin >> num;
			if(num == 2){
				int row1;
				int col1;
				int row2;
				int col2;
				cout << ">> ���� ī�带 ������ (������ ī�带 �� ��� �� : 0, �� : 0)\n";
				cout << "1��° �� : ";
				cin >> row1;
				cout << "1��° �� : ";
				cin >> col1;
				cout << "2��° �� : ";
				cin >> row2;
				cout << "2��° �� : ";
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
				cout << ">> ���� ī�带 ������ (������ ī�带 �� ��� �� : 0, �� : 0)\n";
				cout << "1��° �� : ";
				cin >> row1;
				cout << "1��° �� : ";
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
		cout << "��";
		break;
	case 1 :
		cout << "��";
		break;
	case 2 :
		cout << "��";
		break;
	case 3 :
		cout << "��";
		break;
	} 
	//���ڸ� ����Ѵ�.
	//A J Q K�� ����Ѵ�.
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