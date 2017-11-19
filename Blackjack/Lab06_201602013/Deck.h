#ifndef __DECK_H_
#define __DECK_H_
#include "Card.h"
#include "RummikubCard.h"
#include "TrumpCard.h"

template<class T>
class Deck{
public :
	Deck<T>();
	~Deck<T>();

	void create();
	void createTrump();
	void createRummicub();

	Card* giveCard(T* newCard);
	//Card* giveTrumpCard();
	//Card* giveRummikubCard();
	void clear();

private:
	bool doesCardExist(Card* aCard);

	T* cards[53];
	//TrumpCard* trumpCards[53];
	//RummikubCard* rummikubCards[53];
	int noCard[53];
};
#endif