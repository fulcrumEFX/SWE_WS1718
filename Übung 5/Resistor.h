#pragma once
#include "Component.h"
class CResistor :
	public CComponent
{
private:
	double r;
public:
	CResistor();
	CResistor(double _r);
	~CResistor();
	void setValue(double _r);
	double getValue(void);
	void ausgabe(void);
};

