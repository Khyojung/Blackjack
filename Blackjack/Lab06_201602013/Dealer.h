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
	Deck* getDeck();

	Card* giveCard(int cardChoice);
	void showFirstCard();
	void printAllCard();
	bool over17();

private:
	void printCard(Card* aCard);

	Deck* deck;
	Hand* hand;
};
#endif