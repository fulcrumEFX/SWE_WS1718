#pragma once
#include "Component.h"
class CCapacitor :
	public CComponent
{
private:
	double c;
public:
	CCapacitor();
	CCapacitor(double _c);
	~CCapacitor();
	void setValue(double _c);
	double getValue(void);
	void ausgabe(void);
};

