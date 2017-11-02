#include "stdafx.h"
#include "Resistor.h"


CResistor::CResistor()
{
}
CResistor::CResistor(double _r)
	: r(_r)
{}
CResistor::~CResistor()
{}
void setValue(double _r)
{
	r = _r;
}
double getValue(void)
{
	return r;
}
void ausgabe(void)
{
	cout << "Resistor value: " << getValue() << endl;

	CComponent::ausgabe();
}
