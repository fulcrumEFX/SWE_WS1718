#include "stdafx.h"
#include "Resistor.h"

CResistor::CResistor()
{}

CResistor::CResistor(double _r, double xPos, double yPos, double _price)
	: r(_r), CComponent(_price, CPointy(xPos, yPos))
{
	static int count;
	count++;
	std::ostringstream tempstr;
	tempstr << count;
	std::string s = "R" + tempstr.str();
	this->setName(s);
}
CResistor::~CResistor()
{}
void CResistor::setValue(double _r)
{
	r = _r;
}
void CResistor::setName(std::string _name)
{
	name = _name;
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
