#include "stdafx.h"
#include "Capacitor.h"


CCapacitor::CCapacitor()
	: c(0)
{
}
CCapacitor::CCapacitor(double _c)
	: c(_c)
{}
CCapacitor::CCapacitor(string _name, double _c, double xPos, double yPos, double _price)
	: c(_c), CComponent(_price, CPoint(xPos, yPos), _name)
{}
CCapacitor::~CCapacitor()
{
}
void CCapacitor::setValue(double _c)
{
	c = _c;
}
//void CCapacitor::setOmega(double _omega)
//{
//	omega = _omega;
//}
//double CCapacitor::getOmega(void)
//{
//	return omega;
//}
double CCapacitor::getValue(void)
{
	return c;
}
double CCapacitor::getReal(void)
{
	return 0;
}
double CCapacitor::getImag(double _omega)
{
	return -1 / (c * _omega);
}
CComplex CCapacitor::getComplexImpedance(double _omega)
{
	CComplex _impedance;
	_impedance.setReal(getReal());
	_impedance.setImag(getImag(_omega));
	return _impedance;
}
void CCapacitor::print(void)
{
	cout << "Capacitor value: " << c << endl;

	CComponent::print();
}