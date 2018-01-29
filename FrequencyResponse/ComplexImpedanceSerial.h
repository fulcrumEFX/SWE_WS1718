#pragma once
#include "ComplexImpedance.h"
#include "node.h"


class CComplexImpedanceSerial :
	public CComplexImpedance
{
public:
	
	CComplexImpedanceSerial();
	~CComplexImpedanceSerial();
	CComplex getComplexImpedance(double _omega, node* _head) const;
};

