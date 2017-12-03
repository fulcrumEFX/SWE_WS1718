#include "stdafx.h"
#include "Resistor.h"

CResistor::CResistor()
{}
CResistor::CResistor(double _r)
	: r(_r)
{}
CResistor::CResistor(string _name, double _r, double xPos, double yPos, double _price)
	: r(_r), CComponent(_price, CPointy(xPos, yPos), _name)
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
double CResistor::getReal(void)
{
	return r;
}
double CResistor::getImag(double _omega)
{
	return 0;
}
CComplex CResistor::getComplexImpedance(void)
{
	CComplex _impedance;
	_impedance.setReal(getReal());
	_impedance.setImag(getImag(0));
	return _impedance;
}
