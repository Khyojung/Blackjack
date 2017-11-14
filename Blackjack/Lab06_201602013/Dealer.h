#ifndef __DEALER_H_
#define __DEALER_H_
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

class Dealer{
public :
	//C
	Dealer();
	~Dealer();

	//GS
	Hand* getHand();

	Card* giveCard();
	void showFirstCard();
	void printAllCard();
	bool over17();

private:
	void printCard(Card* aCard);

	Deck* deck;
	Hand* hand;
};
#endif