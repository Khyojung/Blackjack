#include "stdafx.h"
#include "RummikubCard.h"
#include <iostream>

using namespace std;

//Constructor
RummikubCard::RummikubCard(){
}
RummikubCard::RummikubCard(int aShape, int aValue){
	setShape(aShape);
	setValue(aValue);
}
RummikubCard::~RummikubCard(){
}

void RummikubCard::printCard(){
		switch(getShape()){
		case 0 :
			cout << "Black";
			break;
		case 1 :
			cout << "Blue";
			break;
		case 2 :
			cout << "Red";
			break;
		case 3 :
			cout << "Orange";
			break;
		}
		//숫자를 출력한다.
		cout << getValue();
}