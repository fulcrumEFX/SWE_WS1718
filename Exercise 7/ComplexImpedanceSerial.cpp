#include "stdafx.h"
#include "ComplexImpedanceSerial.h"


CComplexImpedanceSerial::CComplexImpedanceSerial()
{}
CComplexImpedanceSerial::~CComplexImpedanceSerial()
{}

CComplex CComplexImpedanceSerial::getComplexImpedance(double _omega)
{
	CComplex result(0,0);
	node *ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next){
		if (ptr->data->getName()[0] == 'R')
		result = result + CComplex(((CResistor*)ptr)->getReal(), ((CResistor*)ptr)->getImag(_omega));
		if (ptr->data->getName()[0] == 'L')
		result = result + CComplex(((CInductor*)ptr)->getReal(), ((CInductor*)ptr)->getImag(_omega));
		if (ptr->data->getName()[0] == 'C')
		result = result + CComplex(((CCapacitor*)ptr)->getReal(), ((CCapacitor*)ptr)->getImag(_omega));
		}
	return result;
}
