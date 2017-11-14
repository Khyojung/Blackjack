#ifndef __HAND_H_
#define __HAND_H_
#include "Card.h"
class Hand{
public :
	//C
	Hand();
	~Hand();

	//GS
	int getSize();
	int* getSum();

	Card* getCard(int number);
	void removeCard(int number);
	bool checkBlackjack();
	bool addCard(Card* newCard);
	bool over21();
	int finalSum();
	void printSum();
	void clear();

private:
	bool checkAce(Card* aCard);

	int size;
	int sum[2];
	Card* cards[30];
};
#endif