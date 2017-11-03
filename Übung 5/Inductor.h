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
	//void setOmega(double _omega);
	double getValue(void);
	//double getOmega(void);
	void ausgabe(void);
};

