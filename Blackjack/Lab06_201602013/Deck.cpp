#include "stdafx.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>

//Constructor
Deck:: Deck(){
	for(int i=0; i<53; i++){
		noCard[i] = 0;
	}
}
Deck::~Deck(){
//	delete[] trumpCards;
//	delete[] rummikubCards;
}

//public method
void Deck::createTrump(){
	for(int i=0; i<52; i++){
		trumpCards[i+1] = new TrumpCard(i/13, i%13+1);
	}
}
void Deck::createRummicub(){
	for(int i=0; i<52; i++){
		rummikubCards[i+1] = new RummikubCard(i/13, i%13+1);
	}
}
Card* Deck::giveTrumpCard(){
	TrumpCard* newCard;
	srand((unsigned int)time(NULL));
	do{
		int newValue = rand() % 13 + 1;
		int newShapeNumber = rand() % 4;

		newCard = trumpCards[newShapeNumber * 13 + newValue];

	}while(!doesCardExist(newCard));

	noCard[newCard->getShape()*13 + newCard->getValue()] = 1;

	return newCard;
}
Card* Deck::giveRummikubCard(){
	RummikubCard* newCard;
	srand((unsigned int)time(NULL));
	do{
		int newValue = rand() % 13 + 1;
		int newShapeNumber = rand() % 4;

		newCard = rummikubCards[newShapeNumber * 13 + newValue];

	}while(!doesCardExist(newCard));

	noCard[newCard->getShape()*13 + newCard->getValue()] = 1;

	return newCard;
}
void Deck::clear(){
	for(int i = 1; i < 53; i++)
		noCard[i] = 0;
}

//private method
bool Deck::doesCardExist(Card* aCard){
	if(noCard[aCard->getShape() * 13 + aCard->getValue()] == 1)
		return false;
	return true;
}