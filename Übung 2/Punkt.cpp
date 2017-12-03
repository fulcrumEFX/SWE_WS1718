#include "stdafx.h"
#include "punkt.h"

CPointy::CPointy()						//Der Konstruktor Initialisiert automatisch die Attribute 
	: x(1), y(1)						//beim Anlegen einer Klasse
{}
CPointy::CPointy(double _x, double _y)	//Überladener Konstruktor
	: x(_x), y(_y)
{}
CPointy::~CPointy()						//Destruktor gibt den Speicherplatz des Objektes wieder frei
{}
void CPointy::setX(double _x) {
	x = _x;
};
void CPointy::setY(double _y) {
	y = _y;
};
double CPointy::getY(void) {
	return y;
};
double CPointy::getX(void) {
	return x;
};
double CPointy::getLength(void) {
	return  sqrt(pow(getX(), 2) + pow(getY(), 2));
};