#include "stdafx.h"
#include "Card.h"

//Constructor
Card::Card(){
	value = 0;
	shapeNumber = 0;
}
Card::Card(int newShapeNumber, int newValue){
	value = newValue;
	shapeNumber = newShapeNumber;
}
Card::~Card(){
}

// getter && setter
int Card::getValue(){
	return value;
}
void Card::setValue(int aValue){
	value = aValue;
}
int Card::getShapeNumber(){
	return shapeNumber;
}
void Card::setShapeNumber(int aShapeNumber){
	shapeNumber = aShapeNumber;
}