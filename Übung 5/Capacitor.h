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
	CCapacitor(string _name, double _c, double xPos, double yPos, double _price);
	~CCapacitor();
	void setValue(double _c);
	double getReal(void);
	double getImag(double _omega);
	double getValue(void);
	CComplex getComplexImpedance(double _omega);
	void print(void);
};
