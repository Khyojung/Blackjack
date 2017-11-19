#include "stdafx.h"
#include "TrumpCard.h"
#include <iostream>

using namespace std;

//Constructor
TrumpCard::TrumpCard(){
	value = 0;
	suit = 0;
}
TrumpCard::TrumpCard(int newSuit, int newValue){
	value = newValue;
	suit = newSuit;
}
TrumpCard::~TrumpCard(){
}

// getter && setter
int TrumpCard::getValue(){
	return value;
}
void TrumpCard::setValue(int aValue){
	value = aValue;
}
int TrumpCard::getSuit(){
	return suit;
}
void TrumpCard::setSuit(int aSuit){
	suit = aSuit;
}


//public method
void TrumpCard::printCard(){
		switch(suit){
		case 0 :
			cout << "��";
			break;
		case 1 :
			cout << "��";
			break;
		case 2 :
			cout << "��";
			break;
		case 3 :
			cout << "��";
			break;
		//���ڸ� ����Ѵ�.
		//A J Q K�� ����Ѵ�.
		switch(value){
		case 1:
			cout << "A";
			break;
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		case 13:
			cout << "K";
			break;
		default:
			cout << value;
		}
	}
}