// Übung 4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "Resistor.h"

int main()
{
	CResistor r1("R1", 1.5, 3, 15, 0.35);
	CInductor l1("L1", 0.05, 7, 1, 0.81);
	CCapacitor c1("C1", 0.0003, 2, 5, 0.15);
	
	cout << r1.getName() << " " << r1.getValue() << "Ohm " << r1.getPrice() << " Euro " << r1.getPosition() << " " << endl;
    return 0;
}

