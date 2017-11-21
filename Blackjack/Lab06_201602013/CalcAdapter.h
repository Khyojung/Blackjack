#pragma once
#include "Calc.h"

class CalcAdapter : public Calc {

private:
	int value;
	int sum[2];

public:
	CalcAdapter();
	~CalcAdapter();

	int getValue() override;
	
	void calculate(Card* newCard);
}