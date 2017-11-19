#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"
#include "TrumpCard.h"
#include "RummikubCard.h"

class PyramidGame : public Game{
public :
	//C
	PyramidGame();
	~PyramidGame();

	//N
	void startGame() override;
		
private :
	//N
	void setCards(int cardChoice);
	void printPyramid();
	void printCard(Card* aCard);
	bool possibleCard(int row, int col);
	bool count13(Card* firstCard, Card* secondCard);
	
	void clear() override;

	void countMoneyWin() override;
	void countMoneyLose() override;
	void countMoneyCompare() override;

	Deck* _deck;
	Card* pyramidCard[9][9];
	int score;
};