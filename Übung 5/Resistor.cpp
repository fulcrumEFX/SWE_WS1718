#include "stdafx.h"
#include "Resistor.h"

CResistor::CResistor()
{}
CResistor::CResistor(double _r)
	: r(_r)
{}
CResistor::CResistor(string _name, double _r, double xPos, double yPos, double _price)
	: r(_r), CComponent(_price, CPoint(xPos, yPos), _name)
{}
CResistor::~CResistor()
{}
void CResistor::setValue(double _r)
{
	r = _r;
}
double CResistor::getValue(void)
{
	return r;
}
void CResistor::ausgabe(void)
{
	cout << "Resistor value: " << r << endl;

	CComponent::ausgabe();
}
