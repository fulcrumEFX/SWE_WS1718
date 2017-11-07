// �bung 4.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
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

	//Aufgabe 5
	CComplex z;
	double omega = 41.09 * 2 * M_PI;
	z.setReal(r1.getReal()+l1.getReal()+c1.getReal());
	z.setImag(r1.getImag()+l1.getImag(omega)+c1.getImag(omega));

	cout << "Z total: " << z << endl;
	cout << "Z in exponential form: " << z.getAbsolute() << "e^(" << z.getAngle() << ")" << endl;

	//Aufgabe 6
	ofstream data;
	data.open("frequency_response.txt");
	for (int i = 1; i < 1001; i++)
	{
		omega = i * 2 * M_PI;
		z.setReal(r1.getReal());
		z.setImag(l1.getImag(omega) + c1.getImag(omega));
		data << z.getAbsolute() << " " << z.getAngle() << endl;
	}
	data.close();
	return 0;
}
