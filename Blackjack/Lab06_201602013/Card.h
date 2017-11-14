#ifndef __CARD_H_
#define __CARD_H_
class Card{
public :
	Card();
	Card(int newShapeNumber, int newValue);
	~Card();
	int getValue();
	void setValue(int aValue);
	int getShapeNumber(); 
	void setShapeNumber(int aShapeNumber);

private:
	int value;
	int shapeNumber;
};
#endif