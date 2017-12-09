#pragma once
#include "ComplexImpedance.h"

class CComplexImpedanceSerial :
	public CComplexImpedance
{
public:
	
	CComplexImpedanceSerial();
	~CComplexImpedanceSerial();
	CComplex getComplexImpedance(double _omega);
};

