#ifndef __DECK_H_
#define __DECK_H_
#include "Card.h"
class Deck{
public :
	Deck();
	~Deck();

	Card* giveCard();
	void clear();

private:
	bool doesCardExist(Card* aCard);

	Card* cards[53];
	int noCard[53];
};
#endif