#include "stdafx.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

//Constuctor
Dealer::Dealer(){
	deck = new Deck();
	hand = new Hand();
}
Dealer::~Dealer(){
	deck->~Deck();
	hand->~Hand();
//	delete deck;
//	delete hand;
}

//getter & setter
Hand* Dealer::getHand(){
	return hand;
}

//public method
Card* Dealer::giveCard(){
	return deck->giveCard();
}
void Dealer::showFirstCard(){
	printCard(hand->getCard(0));
}
void Dealer::printCard(Card* aCard){
	cout << "DEALER : ";
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
		cout << "A" << "	";
		break;
	case 11:
		cout << "J" << "	";
		break;
	case 12:
		cout << "Q" << "	";
		break;
	case 13:
		cout << "K" << "	";
		break;
	default:
		cout << aCard->getValue() << "	";
	}
}
void Dealer::printAllCard(){
	cout << "DEALER : " ;
	for(int i=0; i < hand->getSize(); i++){
		switch(hand->getCard(i)->getShapeNumber()){
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
		switch(hand->getCard(i)->getValue()){
		case 1:
			cout << "A" << "	";
			break;
		case 11:
			cout << "J" << "	";
			break;
		case 12:
			cout << "Q" << "	";
			break;
		case 13:
			cout << "K" << "	";
			break;
		default:
			cout << hand->getCard(i)->getValue() << "	";
		}
	}
}
bool Dealer::over17(){
	if(hand->getSum()[0] > 16 && hand->getSum()[1] > 16)
		return true;
	return false;
}
