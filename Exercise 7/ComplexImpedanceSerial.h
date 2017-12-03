#pragma once
#include "stdafx.h"
#include "ComplexImpedance.h"
#include "LinkedList.h"

class CComplexImpedanceSerial :
	public CComplexImpedance
{
public:
	
	CComplexImpedanceSerial();
	~CComplexImpedanceSerial();
	CComplex getComplexImpedance(double _omega);
};

