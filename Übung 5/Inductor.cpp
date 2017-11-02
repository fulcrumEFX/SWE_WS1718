#include "stdafx.h"
#include "Inductor.h"


CInductor::CInductor()
	:l(0)
{
}
CInductor::CInductor(double _l)
	: l(_l)
{
}
CInductor::~CInductor()
{
}
void CInductor::setValue(double _l)
{
	l = _l;
}
double CInductor::getValue(void)
{
	return l;
}
void ausgabe(void)
{
	cout << "Inductor value: " << getValue() << endl;

	CComponent::ausgabe();
}