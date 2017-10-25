#include "stdafx.h"
#include "punkt.h"

CPunkt::CPunkt()						//Der Konstruktor Initialisiert automatisch die Attribute 
	: x(1), y(1)						//beim Anlegen einer Klasse
{}
CPunkt::CPunkt(double _x, double _y)	//Überladener Konstruktor
	: x(_x), y(_y)
{}
CPunkt::~CPunkt()						//Destruktor gibt den Speicherplatz des Objektes wieder frei
{}
void CPunkt::setX(double _x) {
	x = _x;
};
void CPunkt::setY(double _y) {
	y = _y;
};
double CPunkt::getY(void) {
	return y;
};
double CPunkt::getX(void) {
	return x;
};
double CPunkt::getLength(void) {
	return  sqrt(pow(getX(), 2) + pow(getY(), 2));
};