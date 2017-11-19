#ifndef __TRUMPCARD_H_
#define __TRUMPCARD_H_
class TrumpCard{
public :
	TrumpCard();
	TrumpCard(int newShapeNumber, int newValue);
	~TrumpCard();

	int getValue();
	void setValue(int aValue);
	int getSuit(); 
	void setSuit(int aShapeNumber);

	void printCard() override;

private:
	int value;
	int suit;
};
#endif