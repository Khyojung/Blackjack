#ifndef __CARD_H_
#define __CARD_H_
class Card{
public :
	Card();
	Card(int aShape, int aValue);
	~Card();

	int getValue();
	void setValue(int aValue);
	int getShape(); 
	void setShape(int aShape);

	virtual void printCard()=0;

private:
	int shape;
	int value;
};
#endif