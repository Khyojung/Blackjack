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
	//�Ϲ������� ���� �Է��� ���
	else{
		sum[0] += newCard->getValue();
		sum[1] += newCard->getValue();
	}
}
