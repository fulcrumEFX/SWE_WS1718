
#include "stdafx.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "Resistor.h"
#include "LinkedList.h"


int main(){
	CResistor r1("R1", 1.5, 3, 15, 0.35);
	CResistor r2("R2", 13.1, 8, 11, 0.25);
	CResistor r3("R3", 14.1, 12, 23, 0.56);
	CInductor l1("L1", 0.050, 7, 1, 0.81);
	CInductor l2("L2", 0.150, 17, 4, 3.1);
	CCapacitor c1("C1", 0.0003, 2, 5, 0.15);

	CLinkedList<CComponent> ComponentList;
	ComponentList.add(r1);
	ComponentList.add(r2);
	ComponentList.add(l2);
	ComponentList.add(r3);
	ComponentList.add(l1);
	ComponentList.add(c1);

	/*node<CComponent> *ptr = ComponentList.find(l1);
	ptr->data.print();*/
	ComponentList.print();
	cout << endl;
	ComponentList.del(l1);
	ComponentList.print();
	
	
    return 0;
}

