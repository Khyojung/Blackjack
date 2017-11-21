#include "stdafx.h"
#include "Hand.h"
#include"CalcAdapter.h"
#include <iostream>

using namespace std;

//Constructor
Hand<Card*>::Hand(){
	size = 0;
	cal = new CalcAdapter();
	
}

Hand<Card*>::~Hand(){
}

//getter & setter
Card* Hand<Card*>::getCard(int number){
	map<int, T>::iterator iter;
	iter = cards.find(number);
	return (*iter).second;
}
int Hand<Card*>::getSize(){
	return size;
}

bool Hand<Card*>::checkBlackjack(){
	//�����̵� A & 10
	if(checkAce(getCard(0))){
		int aValue = getCard(1)->getValue();
		if(aValue == 10 || aValue == 11 || aValue == 12 || aValue == 13)
			return true;
	}
	//10 & �����̵� A
	int aValue = getCard(0)->getValue();
	if(aValue == 10 || aValue == 11 || aValue == 12 || aValue == 13){
		if(checkAce(getCard(1)))
			return true;
	}
	//������ �ƴ� ���
	return false;
}



bool Hand<Card*>::addCard(Card* newCard){
	
	//ī�� �ѿ� ī�带 �߰� �Ѵ�.
	cards.insert(pair<int, T>(size, newCard));
	size++;

	cal.calculate(newCard);

	return true;
}

void Hand<Card*>::removeCard(int number){
	cards.erase(size);
	size--;
}

bool Hand<Card*>::over21(){
	// sum[0]�� 21�� ������ sum [1]�� ������ 21�� �Ѵ´�. 
	if(cal.getValue() > 21)
		return true;
	return false;
}

int Hand<Card*>::finalSum(){
	return cal.getValue();
}
void Hand<Card*>::printSum(){
	cout << "POINT : ";
	cout << cal.getValue() << "\n" << endl;

	cout << endl;
}

void Hand<Card*>::clear(){
	size = 0;
}
//private method
template<>
bool Hand<Card*>::checkAce(Card* aCard){
	//���� ī�尡 ���̽����� �ǵ�
	if(aCard->getShape() == 0 && aCard->getValue() == 1)
		return true;
	return false;
}