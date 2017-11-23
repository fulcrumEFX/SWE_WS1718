#include "stdafx.h"
#include "ComplexImpedanceParallel.h"


CComplexImpedanceParallel::CComplexImpedanceParallel()
{
}
CComplexImpedanceParallel::~CComplexImpedanceParallel()
{
}

CComplex CComplexImpedanceParallel::getComplexImpedance(double _omega)
{
	CComplex result(0, 0);
	CComplex temp(0, 0);
	node *ptr = head;
	while (ptr->next != NULL) {
		temp.setReal(ptr->data->getReal());
		temp.setImag(ptr->data->getImag(_omega));
		result = result + temp.getInverse();
		ptr = ptr->next;
	}
	return result.getInverse();
}
