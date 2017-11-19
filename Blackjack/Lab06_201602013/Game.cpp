#include "stdafx.h"
#include "Game.h"
#include <ctime>
#include <iostream>

using namespace std;

//Contructor
Game::Game(){
	_bet = 0;
}
Game::~Game(){
//	delete _player;
//	delete _dealer;
}

//getter & setter
void Game::setPlayer(Player* newPlayer){
	_player = newPlayer;
}
Player* Game::getPlayer(){
	return _player;
}
void Game::setDealer(Dealer* newDealer){
	_dealer = newDealer;
}
Dealer* Game::getDealer(){
	return _dealer;
}
void Game::setBet(double aBet){
	_bet = aBet;
}
double Game::getBet(){
	return _bet;
}

//private method
bool Game::ask(){
	char play;
	try {
		if(_player->getMoney() <= 0) {
			throw 0;
		}
		cout << "Will you play new game? [ y or n ] : " ;
		cin >> play;
		fflush(stdin);
		cout << "\n";
		system("cls");
		if(play != 'y'&&play != 'n')
			throw play;
		if(play == 'y')
			return true;
		return false;
	}
	catch(int bankrupt) {
		cout << endl << "You went bankrupt. You have " << bankrupt << endl;
		cout << "Game Stop" << endl << endl;
		return false;
	}
	catch(char input) {
		cout << "Should input y or n. You input " << input << endl;
		return ask();
	}
}
int Game::cardAsk(){
		int cardChoice;
		cout << "which card will you use?(1.TrumpCard, 2.RummicubCard): " ;
		cin >> cardChoice;
		cout << endl;
		return cardChoice;
}
void Game::countMoneyWin(){
	_player->setMoney((getBet() * 2) + _player->getMoney()); ///////////////// 코드수정
	cout <<	"YOU HAVE : " << _player->getMoney() << "$" << endl;
}
void Game::countMoneyLose(){
	cout <<	"YOU HAVE : " << _player->getMoney() << "$" << endl;
}
void Game::countMoneyCompare(){
	_player->setMoney((getBet() + _player->getMoney()));
	cout <<	"YOU HAVE : " << _player->getMoney() << "$" << endl;
}