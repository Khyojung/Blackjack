#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

class BlackjackGame:public Game{
public :
	//C
	BlackjackGame();
	~BlackjackGame();

	//N
	void startGame() override;
		
private :
	void countMoneyBlackJackWin();
	void countMoneyWin() override;
	void countMoneyLose() override;
	void countMoneyCompare() override;
	void compare();
	void clear() override;
};