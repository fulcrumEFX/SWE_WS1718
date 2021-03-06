
#include "stdafx.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "Resistor.h"
#include "LinkedList.h"


int main(){
	CComponent *cPtr;
	CLinkedList *ComponentList = new CLinkedList;
	
	cPtr = new CResistor (1.5, 3, 15, 0.35);
	ComponentList->add(cPtr);
	cPtr = new CResistor (13.1, 8, 11, 0.25);
	ComponentList->add(cPtr);
	cPtr = new CResistor (14.1, 12, 23, 0.56);
	ComponentList->add(cPtr);
	cPtr = new CInductor (0.050, 7, 1, 0.81);
	ComponentList->add(cPtr);
	cPtr = new CInductor (0.150, 17, 4, 3.1);
	ComponentList->add(cPtr);
	cPtr = new CCapacitor (0.0003, 2, 5, 0.15);
	ComponentList->add(cPtr);
	
	

	ComponentList->print();
	cout << endl;

	node * delPtr = ComponentList->find("R1");
	ComponentList->del(delPtr);
	ComponentList->print();

	double omega = 1;

	bool (*fncPtr1)(node *, string);
	string searchName = "L1";
	fncPtr1 = &nameSearch;

	node * currentComponent = NULL;
	currentComponent = ComponentList->search(fncPtr1, searchName);
	cout << currentComponent->data->getImag(omega) << endl;
	CComplex Impedance;
	
	delete ComponentList;
	
    return 0;
}

