#pragma once
#include "Complex.h"
#include "LinkedList.h"

class CComplexImpedance : public CLinkedList {
public:
	virtual CComplex getComplexImpedance(double _omega) = 0;
};
