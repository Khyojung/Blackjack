#ifndef __DECK_H_
#define __DECK_H_
#include "Card.h"
#include "RummikubCard.h"
#include "TrumpCard.h"

class Deck{
public :
	Deck();
	~Deck();

	void createTrump();
	void createRummicub();
	Card* giveTrumpCard();
	Card* giveRummikubCard();
	void clear();

private:
	bool doesCardExist(Card* aCard);

	TrumpCard* trumpCards[53];
	RummikubCard* rummikubCards[53];
	int noCard[53];
};
#endif