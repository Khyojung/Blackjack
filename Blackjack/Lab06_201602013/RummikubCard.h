#ifndef __RUMMIKUBCARD_H_
#define __RUMMIKUBCARD_H_
#include "Card.h"
class RummikubCard : public Card{
public :
	RummikubCard();
	RummikubCard(int aShape, int aValue);
	~RummikubCard();

	void printCard() override;

private:
	int number;
	int color;
};
#endif