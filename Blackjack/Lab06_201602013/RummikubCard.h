#ifndef __RUMMIKUBCARD_H_
#define __RUMMIKUBCARD_H_
class RummikubCard{
public :
	RummikubCard();
	RummikubCard(int newColor, int newNumber);
	~RummikubCard();

	int getNumber();
	void setNumber(int aNumber);
	int getColor();
	void setColor(int aColor);

	void printCard() override;

private:
	int number;
	int color;
};
#endif