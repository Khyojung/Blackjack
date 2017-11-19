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
	aCard->printCard();
		cout << "	";
}
void Dealer::printAllCard(){
	cout << "DEALER : " ;
	for(int i=0; i < hand->getSize(); i++){
		hand->getCard(i)->printCard();
		cout  << "	";
	}
}
bool Dealer::over17(){
	if(hand->getSum()[0] > 16 && hand->getSum()[1] > 16)
		return true;
	return false;
}
