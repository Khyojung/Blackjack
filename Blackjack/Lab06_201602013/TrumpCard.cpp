#include "stdafx.h"
#include "TrumpCard.h"
#include <iostream>

using namespace std;

//Constructor
TrumpCard::TrumpCard(){
}
TrumpCard::TrumpCard(int aShape, int aValue){
	setShape(aShape);
	setValue(aValue);
}
TrumpCard::~TrumpCard(){
}

//public method
void TrumpCard::printCard(){
	switch(getShape()){
	case 0 :
		cout << "♠";
		break;
	case 1 :
		cout << "♥";
		break;
	case 2 :
		cout << "♣";
		break;
	case 3 :
		cout << "◆";
		break;
	}
	//숫자를 출력한다.
	//A J Q K를 고려한다.
	switch(getValue()){
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
		cout << getValue();
	}
}