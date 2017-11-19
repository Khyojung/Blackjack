#include "stdafx.h"
#include "Card.h"

//Constructor
Card::Card(){
	shape = 0;
	value = 0;
}
Card::Card(int aShape, int aValue){
	shape = aShape;
	value = aValue;
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
int Card::getShape(){
	return shape;
}
void Card::setShape(int aShape){
	shape = aShape;
}