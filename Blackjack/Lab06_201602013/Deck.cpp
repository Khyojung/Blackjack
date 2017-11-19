#include "stdafx.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>

//Constructor
template<class T>
Deck<T>:: Deck(){
	for(int i=0; i<53; i++){
		noCard[i] = 0;
	}
}

//public method

template<class T>
void Deck<T>::createTrump(){
	for(int i=0; i<52; i++){
		trumpCards[i+1] = new TrumpCard(i/13, i%13+1);
	}
}

template<class T>
void Deck<T>::createRummicub(){
	for(int i=0; i<52; i++){
		rummikubCards[i+1] = new RummikubCard(i/13, i%13+1);
	}
}
template<class T>
Card* Deck<T>::giveCard(T* newCard){
	srand((unsigned int)time(NULL));
	do{
		int newValue = rand() % 13 + 1;
		int newShapeNumber = rand() % 4;

		newCard = cards[newShapeNumber * 13 + newValue];

	}while(!doesCardExist(newCard));

	noCard[newCard->getShape()*13 + newCard->getValue()] = 1;

	return newCard;
}

template<class T>
void Deck<T>::clear(){
	for(int i = 1; i < 53; i++)
		noCard[i] = 0;
}

//private method
template<class T>
bool Deck<T>::doesCardExist(Card* aCard){
	if(noCard[aCard->getShape() * 13 + aCard->getValue()] == 1)
		return false;
	return true;
}