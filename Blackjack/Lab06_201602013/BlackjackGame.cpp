#include "stdafx.h"
#include "BlackjackGame.h"
#include <ctime>
#include <iostream>

using namespace std;

//Contructor
BlackjackGame::BlackjackGame(){
	setPlayer(new Player());
	setDealer(new Dealer());
	setBet(0);
}
BlackjackGame::~BlackjackGame(){
	getPlayer()->~Player();
	getDealer()->~Dealer();
//	delete _player;
//	delete _dealer;
}

//public method
void BlackjackGame::startGame(){
	//제일 먼저 쓸 돈을 정한다.
	getPlayer()->setMoney();

	//본격 게임을 시작한다.
	do{
		//어느 카드를 쓸 것인지 확인다.
		int cardChoice= cardAsk();

		if(cardChoice == 1)
			getDealer()->getDeck()->createTrump();
		else if(cardChoice == 2)
			getDealer()->getDeck()->createRummicub();


		//게임 시작
		cout << "===========================================================" << endl;
		cout << "★★★GAME START★★★" << endl;
		cout << "===========================================================" << endl;

		setBet(getPlayer()->betting());
		cout << endl;
		cout << "★★★GOOD LUCK★★★" << endl;
		cout << endl;

		//초반 카드를 준다. setting
		for(int i = 2; i > 0; i--){
			getPlayer()->getHand()->addCard(getDealer()->giveCard(cardChoice));
			getDealer()->getHand()->addCard(getDealer()->giveCard(cardChoice));
		}

		//dealer의 setting card 중 첫 카드를 출력해준다.
		getDealer()->showFirstCard();
		cout << endl;

		//player의 setting cards를 출력해준다.
		getPlayer()->printAllCard();
		getPlayer()->getHand()->printSum();
		cout << endl;
		
		//player의 첫 카드가 Blackjack 인지 확인한다.
		if(getPlayer()->getHand()->checkBlackjack() && !getDealer()->getHand()->checkBlackjack()){
			cout << "★★★BLACKJACK★★★" << endl;
			cout << " ★★★YOU WIN★★★" << endl;
			countMoneyBlackJackWin();
		}
		else if(getPlayer()->getHand()->checkBlackjack() && getDealer()->getHand()->checkBlackjack()){
			cout << "★★★BOTH BLACKJACK★★★" << endl;
			cout << " ★★★YOU TIE★★★" << endl;
		}
		else if(!getPlayer()->getHand()->checkBlackjack() && getDealer()->getHand()->checkBlackjack()){
			cout << "★★★DEALER BLACKJACK★★★" << endl;
			cout << " ★★★YOU LOSE★★★" << endl;
			countMoneyLose();
		}
		else{
			srand((unsigned int)time(NULL));
			while(getPlayer()->hitOrStand()){
				Card* newCard = getDealer()->giveCard(cardChoice);
				if(getPlayer()->getHand()->addCard(newCard)){
					getPlayer()->printAllCard();
					getPlayer()->getHand()->printSum();
				}
				if(getPlayer()->getHand()->over21())
					break;
			}// player stand

			if(!getPlayer()->getHand()->over21()){
				//player가 over되지 않고 stand를 하면 딜러가 카드를 받고 다 받으면 출력한다.
				srand((unsigned int)time(NULL));
				while(!getDealer()->over17()){
					Card* newCard = getDealer()->giveCard(cardChoice);
					getDealer()->getHand()->addCard(newCard);
				}
				getDealer()->printAllCard();
				getDealer()->getHand()->printSum();

				//딜러의 카드가 21이 넘으면 player 승
				if(getDealer()->getHand()->over21()){
					cout << "★★★DEALER BUST★★★" << endl;
					cout << "★★★YOU WIN★★★" << endl;
					countMoneyWin();
				}
				else
					compare();
			}
			else{
				cout << "★★★YOU BUST★★★" << endl;
				cout << "★★★YOU LOSE★★★" << endl;
				cout << endl;
				countMoneyLose();
			}
			cout << "===========================================================\n\n" << endl;
		}
		clear();
	}while( ask() );
}

//private method
void BlackjackGame::countMoneyBlackJackWin(){
	getPlayer()->setMoney((getBet() * 2.5) + getPlayer()->getMoney());
	cout <<	"YOU HAVE : " << getPlayer()->getMoney() << "$" << endl;
}
void BlackjackGame::countMoneyWin(){
	getPlayer()->setMoney((getBet() * 2) + getPlayer()->getMoney()); ///////////////// 코드수정
	cout <<	"YOU HAVE : " << getPlayer()->getMoney() << "$" << endl;
}
void BlackjackGame::countMoneyLose(){
	cout <<	"YOU HAVE : " << getPlayer()->getMoney() << "$" << endl;
}
void BlackjackGame::countMoneyCompare(){
	getPlayer()->setMoney((getBet() + getPlayer()->getMoney()));
	cout <<	"YOU HAVE : " << getPlayer()->getMoney() << "$" << endl;
}


void BlackjackGame::compare(){
	if(getPlayer()->getHand()->finalSum() > getDealer()->getHand()->finalSum()){
		cout << "★★★YOU WIN★★★" << endl;
		countMoneyWin();
	}
	else if(getPlayer()->getHand()->finalSum() == getDealer()->getHand()->finalSum()){
		cout << "★★★PUSH★★★" << endl;
		cout << "★★★YOU TIE★★★" << endl;
		countMoneyCompare();
	}
	else{
		cout << "★★★YOU LOSE★★★" << endl;
		countMoneyLose();
	}
	cout << endl;
}

void BlackjackGame::clear(){
	getPlayer()->getHand()->clear();
	getDealer()->getHand()->clear();
	setBet(0);
}