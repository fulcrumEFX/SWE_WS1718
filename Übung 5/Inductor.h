#pragma once
#include "Component.h"
class CInductor :
	public CComponent
{
private:
	double l;
	double omega;
public:
	CInductor();
	CInductor(double _l);
	CInductor(string _name, double _l, double xPos, double yPos, double _price);
	~CInductor();
	void setValue(double _l);
	double getReal(void);
	double getImag(double _omega);
	CComplex getComplexImpedance(double _omega);
	double getValue(void);
	void print(void);
};
