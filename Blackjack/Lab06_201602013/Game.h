#ifndef __GAME_H_
#define __GAME_H_
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

class Game{
public :
	//C
	Game();
	~Game();

	//N
	virtual void startGame() = 0;
		

protected :
	//GS
	void setPlayer(Player* newPlayer);
	Player* getPlayer();
	void setDealer(Dealer* newDealer);
	Dealer* getDealer();
	void setBet(double aBet);
	double getBet();
		
	//N
	bool ask();

	virtual void countMoneyWin() = 0;
	virtual void countMoneyLose() = 0;
	virtual void countMoneyCompare() = 0;

	virtual void clear() = 0;


private :
	Player* _player;
	Dealer* _dealer;
	double _bet;
};

#endif