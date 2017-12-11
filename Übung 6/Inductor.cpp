#include "stdafx.h"
#include "Inductor.h"


CInductor::CInductor()
	:l(0)
{}
CInductor::CInductor(string _name, double _l, double xPos, double yPos, double _price)
	: l(_l), CComponent(_price, CPointy(xPos, yPos), _name)
{}
CInductor::CInductor(double _l, double xPos, double yPos, double _price)
	: l(_l), CComponent(_price, CPointy(xPos, yPos))
{
	static int count;
	count++;
	ostringstream tempstr;
	tempstr << count;
	string s = "L" + tempstr.str();
	this->setName(s);
}
CInductor::~CInductor()
{}
void CInductor::setValue(double _l)
{
	l = _l;
}
double CInductor::getValue(void)
{
	return l;
}
double CInductor::getReal(void)
{
	return 0;
}
double CInductor::getImag(double _omega)
{
	return l * _omega;
}
CComplex CInductor::getComplexImpedance(double _omega)
{
	CComplex _impedance;
	_impedance.setReal(getReal());
	_impedance.setImag(getImag(_omega));
	return _impedance;
}
void CInductor::print(void)
{
	cout << "Inductor value: " << l << endl;

	CComponent::print();
}
