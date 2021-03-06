#ifndef __PLAYER_H_
#define __PLAYER_H_
#include "Hand.h"
#include "Card.h"
class Player{
public :
	//C
	Player();
	~Player();

	//GS
	double getMoney();
	void setMoney();
	void setMoney(double newMoney);
	Hand<Card*>* getHand();
	void setHand(Hand<Card*>* newHand);

	double betting();
	bool hitOrStand();
	void printAllCard();

private:
	double money;
	Hand<Card*>* hand;
};
#endif