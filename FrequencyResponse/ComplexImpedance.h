#pragma once
#include "Complex.h"
#include "node.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"

class CComplexImpedance {
public:
	virtual CComplex getComplexImpedance(double _omega, node* _head) const = 0;
};
