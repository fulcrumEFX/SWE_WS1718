#include "stdafx.h"
#include "ComplexImpedanceSerial.h"


CComplexImpedanceSerial::CComplexImpedanceSerial()
{
}


CComplexImpedanceSerial::~CComplexImpedanceSerial()
{
}

CComplex CComplexImpedanceSerial::getComplexImpedance(double _omega)
{
	CComplex result;
	CComplex temp;
	node *ptr = head;
	while (ptr->next != NULL) {
		temp.setReal(ptr->data->getReal());
		temp.setImag(ptr->data->getImag(_omega));
		result = result + temp;
		ptr = ptr->next;
	}
	return result;
}
