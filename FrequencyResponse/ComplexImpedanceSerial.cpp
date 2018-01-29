#include "stdafx.h"
#include "ComplexImpedanceSerial.h"




CComplexImpedanceSerial::CComplexImpedanceSerial()
{}
CComplexImpedanceSerial::~CComplexImpedanceSerial()
{}

CComplex CComplexImpedanceSerial::getComplexImpedance(double _omega, node* _head) const
{
	CComplex result(0,0);
	node *ptr = NULL;
	for (ptr = _head; ptr != NULL; ptr = ptr->next) {
		//result = result + CComplex((ptr->data)->getReal(), ptr->data->getImag(_omega));
		if (ptr->data->getName()[0] == 'R')
		result = result + CComplex(((CResistor*)ptr->data)->getReal(), ((CResistor*)ptr->data)->getImag(_omega));
		if (ptr->data->getName()[0] == 'L')
		result = result + CComplex(((CInductor*)ptr->data)->getReal(), ((CInductor*)ptr->data)->getImag(_omega));
		if (ptr->data->getName()[0] == 'C')
		result = result + CComplex(((CCapacitor*)ptr->data)->getReal(), ((CCapacitor*)ptr->data)->getImag(_omega));
		
		}
	return result;
}
