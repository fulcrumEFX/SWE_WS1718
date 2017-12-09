#pragma once
#include "ComplexImpedance.h"

class CComplexImpedanceParallel :
	public CComplexImpedance
{
public:

	CComplexImpedanceParallel();
	~CComplexImpedanceParallel();
	CComplex getComplexImpedance(double _omega);
};

