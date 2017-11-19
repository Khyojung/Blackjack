#include "stdafx.h"
#include "Hand.h"
#include <iostream>

using namespace std;

//Constructor
Hand<Card*>::Hand(){
	size = 0;
	sum[0] = 0;
	sum[1] = 0;
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
int* Hand<Card*>::getSum(){
	return sum;
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

void Hand<Card*>::calculate(Card* newCard){
	//�հ踦 ����Ѵ�. 
	//�����̵� A�� ���� ��츦 Ȯ���Ѵ�.
	if(newCard->getShape() == 0 && newCard->getValue() == 1){
		
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
}

bool Hand<Card*>::addCard(Card* newCard){
	//ī�� �ѿ� ī�带 �߰� �Ѵ�.
	cards.insert(pair<int, T>(size, newCard));
	size++;

	calculate(newCard);

	return true;
}

void Hand<Card*>::removeCard(int number){
	cards.erase(size);
	size--;
}

bool Hand<Card*>::over21(){
	if(sum[0] > 21 && sum[1] > 21)
		return true;
	return false;
}

int Hand<Card*>::finalSum(){
	if(sum[1] > 21)
		return sum[0];
	else
		return sum[1];
}
void Hand<Card*>::printSum(){
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

void Hand<Card*>::clear(){
	size = 0;
	sum[0] = 0;
	sum[1] = 0;
}
//private method
template<>
bool Hand<Card*>::checkAce(Card* aCard){
	//���� ī�尡 ���̽����� �ǵ�
	if(aCard->getShape() == 0 && aCard->getValue() == 1)
		return true;
	return false;
}