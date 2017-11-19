#include "stdafx.h"
#include "RummikubCard.h"

//Constructor
RummikubCard::RummikubCard(){
	number = 0;
	color = 0;
}
RummikubCard::RummikubCard(int newColor, int newNumber){
	number = newNumber;
	color = newColor;
}
RummikubCard::~RummikubCard(){
}

// getter && setter
int RummikubCard::getNumber(){
	return number;
}
void RummikubCard::setNumber(int aNumber){
	number = aNumber;
}
int RummikubCard::getColor(){
	return color;
}
void RummikubCard::setColor(int aColor){
	color = aColor;
}