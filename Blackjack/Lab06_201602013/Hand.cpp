#include "stdafx.h"
#include "Hand.h"
#include <iostream>

using namespace std;

//Constructor
Hand::Hand(){
	size = 0;
	sum[0] = 0;
	sum[1] = 0;
}
Hand::~Hand(){
}

//getter & setter
Card* Hand::getCard(int number){
	return cards[number];
}
int Hand::getSize(){
	return size;
}
int* Hand::getSum(){
	return sum;
}

bool Hand::checkBlackjack(){
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

bool Hand::addCard(Card* newCard){
	//ī�� �ѿ� ī�带 �߰� �Ѵ�.
	cards[size] = newCard;
	size++;

	//�հ踦 ����Ѵ�. 
	//�����̵� A�� ���� ��츦 Ȯ���Ѵ�.
	if(newCard->getShapeNumber() == 0 && newCard->getValue() == 1){
		
		sum[0] += newCard->getValue();
		sum[1] += newCard->getValue() + 10;
	}
	//J Q K�� ���� ��츦 ����Ѵ�.
	else if(newCard->getValue() > 10){
			sum[0] += 10;
			sum[1] += 10;
	}
	else{
		sum[0] += newCard->getValue();
		sum[1] += newCard->getValue();
	}

	return true;
}
void Hand::removeCard(int number){
	cards[number] = NULL;
	for(int i = number; i < size; i++){
		cards[i] = cards[i+1];
	}
	cards[size] = NULL;
	size--;
}
bool Hand::over21(){
	if(sum[0] > 21 && sum[1] > 21)
		return true;
	return false;
}
int Hand::finalSum(){
	if(sum[1] > 21)
		return sum[0];
	else
		return sum[1];
}
void Hand::printSum(){
	cout << "POINT : ";
	if(sum[1] > 21)
		cout << sum[0] << "\n" << endl;
	else{
		cout << sum[0] << "	";
		if(sum[0] != sum[1])
			cout << sum[1] << "\n";
		cout << endl;
	}
	cout << endl;
}
void Hand::clear(){
	size = 0;
	sum[0] = 0;
	sum[1] = 0;
}
//private method
bool Hand::checkAce(Card* aCard){
	//���� ī�尡 ���̽����� �ǵ�
	if(aCard->getShapeNumber() == 0 && aCard->getValue() == 1)
		return true;
	return false;
}