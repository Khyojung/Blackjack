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
	//���� ���� �� ���� ���Ѵ�.
	getPlayer()->setMoney();

	//���� ������ �����Ѵ�.
	do{
		//��� ī�带 �� ������ Ȯ�δ�.
		int cardChoice= cardAsk();

		if(cardChoice == 1)
			getDealer()->getDeck()->createTrump();
		else if(cardChoice == 2)
			getDealer()->getDeck()->createRummicub();


		//���� ����
		cout << "===========================================================" << endl;
		cout << "�ڡڡ�GAME START�ڡڡ�" << endl;
		cout << "===========================================================" << endl;

		setBet(getPlayer()->betting());
		cout << endl;
		cout << "�ڡڡ�GOOD LUCK�ڡڡ�" << endl;
		cout << endl;

		//�ʹ� ī�带 �ش�. setting
		for(int i = 2; i > 0; i--){
			getPlayer()->getHand()->addCard(getDealer()->giveCard(cardChoice));
			getDealer()->getHand()->addCard(getDealer()->giveCard(cardChoice));
		}

		//dealer�� setting card �� ù ī�带 ������ش�.
		getDealer()->showFirstCard();
		cout << endl;

		//player�� setting cards�� ������ش�.
		getPlayer()->printAllCard();
		getPlayer()->getHand()->printSum();
		cout << endl;
		
		//player�� ù ī�尡 Blackjack ���� Ȯ���Ѵ�.
		if(getPlayer()->getHand()->checkBlackjack() && !getDealer()->getHand()->checkBlackjack()){
			cout << "�ڡڡ�BLACKJACK�ڡڡ�" << endl;
			cout << " �ڡڡ�YOU WIN�ڡڡ�" << endl;
			countMoneyBlackJackWin();
		}
		else if(getPlayer()->getHand()->checkBlackjack() && getDealer()->getHand()->checkBlackjack()){
			cout << "�ڡڡ�BOTH BLACKJACK�ڡڡ�" << endl;
			cout << " �ڡڡ�YOU TIE�ڡڡ�" << endl;
		}
		else if(!getPlayer()->getHand()->checkBlackjack() && getDealer()->getHand()->checkBlackjack()){
			cout << "�ڡڡ�DEALER BLACKJACK�ڡڡ�" << endl;
			cout << " �ڡڡ�YOU LOSE�ڡڡ�" << endl;
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
				//player�� over���� �ʰ� stand�� �ϸ� ������ ī�带 �ް� �� ������ ����Ѵ�.
				srand((unsigned int)time(NULL));
				while(!getDealer()->over17()){
					Card* newCard = getDealer()->giveCard(cardChoice);
					getDealer()->getHand()->addCard(newCard);
				}
				getDealer()->printAllCard();
				getDealer()->getHand()->printSum();

				//������ ī�尡 21�� ������ player ��
				if(getDealer()->getHand()->over21()){
					cout << "�ڡڡ�DEALER BUST�ڡڡ�" << endl;
					cout << "�ڡڡ�YOU WIN�ڡڡ�" << endl;
					countMoneyWin();
				}
				else
					compare();
			}
			else{
				cout << "�ڡڡ�YOU BUST�ڡڡ�" << endl;
				cout << "�ڡڡ�YOU LOSE�ڡڡ�" << endl;
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
	getPlayer()->setMoney((getBet() * 2) + getPlayer()->getMoney()); ///////////////// �ڵ����
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
		cout << "�ڡڡ�YOU WIN�ڡڡ�" << endl;
		countMoneyWin();
	}
	else if(getPlayer()->getHand()->finalSum() == getDealer()->getHand()->finalSum()){
		cout << "�ڡڡ�PUSH�ڡڡ�" << endl;
		cout << "�ڡڡ�YOU TIE�ڡڡ�" << endl;
		countMoneyCompare();
	}
	else{
		cout << "�ڡڡ�YOU LOSE�ڡڡ�" << endl;
		countMoneyLose();
	}
	cout << endl;
}

void BlackjackGame::clear(){
	getPlayer()->getHand()->clear();
	getDealer()->getHand()->clear();
	setBet(0);
}