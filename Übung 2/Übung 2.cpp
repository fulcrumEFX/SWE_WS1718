// Übung 2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "punkt.h"

int main()
{
	CPointy p1, p2;

	p1.setX(1.3);
	p1.setY(4.2);

	p2.setX(3);
	p2.setY(-2);

	cout << "Punkt 1: (" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "Abstand Punkt 1 vom Ursprung: " << p1.getLength() << endl;
	cout << "Punkt 2: (" << p2.getX() << "," << p2.getY() << ")" << endl;	
	cout << "Abstand Punkt 2 vom Ursprung: " << p2.getLength() << endl;

	double x_temp, y_temp;
	cout << "Punkt 3" << endl << "X = "; cin >> x_temp; cout << "Y = "; cin >> y_temp;	
	CPointy p3(x_temp, y_temp);
	cout << "Punkt 4" << endl << "X = "; cin >> x_temp; cout << "Y = "; cin >> y_temp;
	CPointy p4(x_temp, y_temp);

	cout << "Punkt 3: (" << p3.getX() << "," << p3.getY() << ")" << endl;
	cout << "Abstand Punkt 3 vom Ursprung: " << p3.getLength() << endl;
	cout << "Punkt 4: (" << p4.getX() << "," << p4.getY() << ")" << endl;
	cout << "Abstand Punkt 4 vom Ursprung: " << p4.getLength() << endl;
	
    return 0;
}

