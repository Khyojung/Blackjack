#ifndef __TRUMPCARD_H_
#define __TRUMPCARD_H_
#include "Card.h"

class TrumpCard : public Card{
public :
	TrumpCard();
	TrumpCard(int aShape, int aValue);
	~TrumpCard();

	void printCard() override;
};
#endif