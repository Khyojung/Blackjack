#ifndef __PEOPLE_H_
#define __PEOPLE_H_
#include "Card.h"
#include <iostream>

using namespace std;

class People{
public :
	People();
	virtual ~People();

	int getSize();
	void setSize(int newSize);
	int* getSum();
	Card* getCardPack();

	virtual bool addCard(Card newCard) = 0;
	virtual void countSum() = 0;
	virtual void printAllCard() = 0;
	virtual bool checkBlackJack() = 0;
	virtual bool over21() = 0;

protected:
	void setSum(int aSum);
	virtual Card getCardWithNumber(int number) = 0;

private:
	virtual bool checkAce(Card aCard) = 0;

	int size;
	int sum[2];
	Card cardPack[10];
};
#endif