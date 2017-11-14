#include "stdafx.h"
#include "People.h"

//constructor
People::People(){
}
People::~People(){
}

//getter & setter
int People::getSize(){
	return size;
}
void People::setSize(int newSize){
	size = newSize;
}
int* People::getSum(){
	return sum;
}
void People::setSum(int aSum){
	sum[0] = aSum;
	sum[1] = aSum;
}
Card* People::getCardPack(){
	return cardPack;
}