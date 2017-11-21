#include "stdafx.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

//Constuctor
Dealer::Dealer(){
	deck = new Deck();
	hand = new Hand<Card*>();
}
Dealer::~Dealer(){
	deck->~Deck();
	hand->~Hand();
//	delete deck;
//	delete hand;
}

//getter & setter
Hand<Card*>* Dealer::getHand(){
	return hand;
}
void Dealer::setHand(Hand<Card*>* newHand){
	hand = newHand;
}
Deck* Dealer::getDeck(){
	return deck;
}

//public method
Card* Dealer::giveCard(int cardChoice){
	if(cardChoice == 1)
		return deck->giveTrumpCard();
	else if(cardChoice == 2)
		return deck->giveRummikubCard();
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
	if(hand->cal.getValue() > 16)
		return true;
	return false;
}
