// Übung 4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Complex.h"
#include "Vector.h"

int main()
{
	const CComplex J(0, 1);
	CComplex c1(3, 4), c2(1, 1), c3(8, 9), c4(7, -4);
	c3 = c1 + c2;

	cout << "Komplexe Zahl: " << J << endl;

	CVector v1(CPoint(1, 2), CPoint(4, 9));
	cout << "Vektor v1: " << v1 << endl;
    return 0;
}

