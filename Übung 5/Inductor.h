#pragma once
#include "Component.h"
class CInductor :
	public CComponent
{
private:
	double l;
public:
	CInductor();
	CInductor(double _l);
	~CInductor();
	void setValue(double _l);
	double getValue(void);
	void ausgabe(void);
};

