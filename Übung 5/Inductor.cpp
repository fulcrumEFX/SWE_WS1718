#include "stdafx.h"
#include "Inductor.h"


CInductor::CInductor()
	:l(0)
{}
CInductor::CInductor(double _l)
	: l(_l)
{}
CInductor::CInductor(string _name, double _l, double xPos, double yPos, double _price)
	: l(_l), CComponent(_price, CPoint(xPos, yPos), _name)
{}
CInductor::~CInductor()
{}
void CInductor::setValue(double _l)
{
	l = _l;
}
//void CInductor::setOmega(double _omega)
//{
//	omega = _omega;
//}
//double CInductor::getOmega(void)
//{
//	return omega;
//}
double CInductor::getValue(void)
{
	return l;
}

void CInductor::ausgabe(void)
{
	cout << "Inductor value: " << l << endl;

	CComponent::ausgabe();
}