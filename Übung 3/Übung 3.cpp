// Übung 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bauelement.h"
#include "Punkt.h"


int main()
{
	CBauelement b1(3.5, CPointy(3.5, 7.7));
	CBauelement b2(1.8850, CPointy(1.5, 0.7));
	CBauelement b3(0.50, CPointy(12.1, 3.7));
	
	cout << "Bauelement 1:" << endl << "Preis: " << b1.getKosten() << " Euro" << endl << "Position: " << b1.getPosition() << endl << endl;
	cout << "Bauelement 2:" << endl << "Preis: " << b2.getKosten() << " Euro" << endl << "Position: " << b2.getPosition() << endl << endl;
	cout << "Bauelement 3:" << endl << "Preis: " << b3.getKosten() << " Euro" << endl << "Position: " << b3.getPosition() << endl << endl;

	CBauelement b4;				//Konstruktor von CPunkt wird automatisch aufgerufen
	cout << "Bauelement 4:" << endl << "Preis: " << b4.getKosten() << " Euro" << endl << "Position: " << b4.getPosition() << endl << endl;
	
	CBauelement b5(b1);
	cout << "Bauelement 5:" << endl << "Preis: " << b5.getKosten() << " Euro" << endl << "Position: " << b5.getPosition() << endl << endl;

	return 0;
}

