#include "stdafx.h"
#include "Capacitor.h"


CCapacitor::CCapacitor()
	: c(0)
{
}
CCapacitor::CCapacitor(double _c)
	: c(_c)
{}
CCapacitor::~CCapacitor()
{
}
void CCapacitor::setValue(double _c)
{
	c = _c;
}
double CCapacitor::getValue(void)
{
	return c;
}
void ausgabe(void)
{
	cout << "Capacitor value: " << getValue() << endl;

	CComponent::ausgabe();
}