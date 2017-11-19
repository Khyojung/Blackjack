#ifndef __CARD_H_
#define __CARD_H_
class Card{
public :
	Card();
	~Card();
	
	virtual void printCard()=0;
};
#endif