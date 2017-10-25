// Übung3 Wiederverwendung vorhandener Klassen.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Bauelement.h"
#include "Punkt.h"


int main()
{
	CBauelement b1(3.5, CPunkt(3.5, 7.7));
	CBauelement b2(1.8850, CPunkt(1.5, 0.7));
	CBauelement b3(0.50, CPunkt(12.1, 3.7));

	cout << "Bauelement 1:" << endl << "Preis: " << b1.getKosten() << endl << "Position: " << b1.getPosition() << endl;

    return 0;
}

