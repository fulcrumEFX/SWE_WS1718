#include "stdafx.h"
#include "ComplexImpedanceParallel.h"



CComplexImpedanceParallel::CComplexImpedanceParallel()
{}
CComplexImpedanceParallel::~CComplexImpedanceParallel()
{}

CComplex CComplexImpedanceParallel::getComplexImpedance(double _omega, node* _head)
{
	CComplex result(0, 0);
	node *ptr = NULL;
	for (ptr = _head; ptr != NULL; ptr = ptr->next){
		if (ptr->data->getName()[0] == 'R')
		result = result + CComplex(((CResistor*)ptr)->getReal(), ((CResistor*)ptr)->getImag(_omega)).getInverse();
		if (ptr->data->getName()[0] == 'L')
		result = result + CComplex(((CInductor*)ptr)->getReal(), ((CInductor*)ptr)->getImag(_omega)).getInverse();
		if (ptr->data->getName()[0] == 'C')
		result = result + CComplex(((CCapacitor*)ptr)->getReal(), ((CCapacitor*)ptr)->getImag(_omega)).getInverse();
		}
	return result.getInverse();
}
