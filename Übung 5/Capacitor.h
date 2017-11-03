#pragma once
#include "Component.h"
class CCapacitor :
	public CComponent
{
private:
	double c;
	//double omega;
public:
	CCapacitor();
	CCapacitor(double _c);
	CCapacitor(string _name, double _c, double xPos, double yPos, double _price);
	~CCapacitor();
	void setValue(double _c);
	//void setOmega(double _omega);
	double getValue(void);
	//double getOmega(void);
	void ausgabe(void);
};

