#include"CalcAdapter.h"

CalcAdapter::CalcAdapter(){
	sum[0] = 0;
	sum[1] = 0;

}
CalcAdapter::~CalcAdapter(){

}
int CalcAdapter::getValue(){

	if(sum[1] > 21)
		value =  sum[0];
	else
		value =  sum[1];

	return value;
}
void CalcAdapter::calculate(Card* newCard){
	//합계를 계산한다. 
	//스페이드 A가 나올 경우를 확인한다.
	if(newCard->getShape() == 0 && newCard->getValue() == 1){
		
		sum[0] += newCard->getValue();
		sum[1] += newCard->getValue() + 10;
	}
	//J Q K가 나올 경우를 계산한다.
	else if(newCard->getValue() > 10){
			sum[0] += 10;
			sum[1] += 10;
	}
	//일반적으로 값을 입력할 경우
	else{
		sum[0] += newCard->getValue();
		sum[1] += newCard->getValue();
	}
}
