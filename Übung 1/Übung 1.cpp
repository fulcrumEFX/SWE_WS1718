// Übung1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Vektor {
	double x; 
	double y;
};

double minFinden(Vektor feld[], int laenge) {
	double min = sqrt(pow(feld[0].x, 2) + pow(feld[0].y, 2));
	for (int i = 1; i < laenge; i++) {
		if ((sqrt(pow(feld[i].x, 2) + pow(feld[i].y, 2))) < min)
			min = sqrt(pow(feld[i].x, 2) + pow(feld[i].y, 2));
	}
	return min;
}

int main()
{
	
	Vektor Vektorfeld[5] = { 2,3, 4,-1, 5,9, 12,3, 1,1 }
};
	//int zahlenfeld[10] = { 1,6,2,9,-12,5,23,45,-45,14 };
	cout << endl << "Min. Wert = " << minFinden(Vektorfeld, 5);

    return 0;
}

