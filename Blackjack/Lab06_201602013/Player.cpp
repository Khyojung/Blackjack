#include "stdafx.h"
#include "Player.h"
#include <iostream>

using namespace std;

//Constructor
Player::Player(){
	hand = new Hand();
}
Player::~Player(){
	hand->~Hand();
//	delete hand;
}

//getter & setter
void Player::setMoney(){
	try {
		cout << "How much $ do you have? : ";
		cin >> money;
		if(money <= 0)
			throw 0;
		else
			return;
	}
	catch (int zero) {
		cout << "Low Money!!(Money should over " << zero << ")" <<endl;
		setMoney();
		return;
	}
}
void Player::setMoney(double newMoney){
	money = newMoney;
}
double Player::getMoney(){
	return money;
}
Hand* Player::getHand(){
	return hand;
}
void Player::setHand(Hand* newHand){
	hand = newHand;
}

//Public method
double Player::betting(){
	int bet;
	do{
		try {
			cout << "YOU HAVE : " << getMoney() <<  endl;
			cout << "How much will you bet? : ";
			cin >> bet;
			if(getMoney() < bet)
				throw false;
			if(bet <= 0)
				throw bet;
		}
		catch (bool c) {
			system("cls");
			cout << "You don't have enough\n" << endl;
			return betting();
		}
		catch (int err) {
			system("cls");
			cout << "Low bet!!(Bet should over 0) You input " << err << endl;
			return betting();
		}
	}while(getMoney() < bet);
	setMoney(getMoney() - bet);
	return bet;
}
bool Player::hitOrStand(){
	int hit;
	try {
		cout << "Hit or Stand?	1. Hit	2. Stand : ";
		cin >> hit;
		cout << endl;
		if (hit == 1)
			return true;
		else if (hit == 2)
			return false;
		else
			throw hit;
	}
	catch (int err) {
		cout << "Wrong Input! You input " << err << endl;
		return hitOrStand();
	}
}
void Player::printAllCard(){
	cout << "PLAYER : " ;
	for(int i=0; i < hand->getSize(); i++){
		hand->getCard(i)->printCard();
		cout  << "	";
	}
}