#include "stdafx.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>

//Constructor
Deck:: Deck(){
	for(int i=0; i<52; i++){
		cards[i+1] = new Card(i/13, i%13+1);
	}
	for(int i=0; i<53; i++){
		noCard[i] = 0;
	}
}
Deck::~Deck(){
	delete[] cards;
}

//public method
Card* Deck::giveCard(){
	Card* newCard;
	srand((unsigned int)time(NULL));
	do{
		int newValue = rand() % 13 + 1;
		int newShapeNumber = rand() % 4;

		newCard = cards[newShapeNumber * 13 + newValue];

	}while(!doesCardExist(newCard));

	noCard[newCard->getShapeNumber()*13 + newCard->getValue()] = 1;

	return newCard;
}

//private method
bool Deck::doesCardExist(Card* aCard){
	if(noCard[aCard->getShapeNumber() * 13 + aCard->getValue()] == 1)
		return false;
	return true;
}
void Deck::clear(){
	for(int i = 1; i < 53; i++)
		noCard[i] = 0;
}