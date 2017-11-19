#ifndef __HAND_H_
#define __HAND_H_
#include "Card.h"
#include <map>

using namespace std;

template<class T>

class Hand{
private:
	bool checkAce(Card* aCard);

	int size;
	int sum[2];
	//Card* cards[30];

	map<int, T> cards;
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
	void calculate(Card* newCard);


};
#endif