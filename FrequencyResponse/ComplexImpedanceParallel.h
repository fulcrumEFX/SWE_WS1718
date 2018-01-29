#pragma once
#include "ComplexImpedance.h"
#include "node.h"


class CComplexImpedanceParallel :
	public CComplexImpedance
{
public:
	CComplexImpedanceParallel();
	~CComplexImpedanceParallel();
	CComplex getComplexImpedance(double _omega, node* _head) const;
};

