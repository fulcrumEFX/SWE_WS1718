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
	CResistor(string _name, double _r, double xPos, double yPos, double _price);
	~CResistor();
	void setValue(double _r);
	double getValue(void);
	double getReal(void);
	double getImag(double _omega);
	CComplex getComplexImpedance(void);
};

