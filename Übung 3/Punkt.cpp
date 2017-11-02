#include "stdafx.h"
#include "punkt.h"

CPoint::CPoint()						//Der Konstruktor Initialisiert automatisch die Attribute 
	: x(0), y(0)						//beim Anlegen einer Klasse
{}
CPoint::CPoint(double _x, double _y)	//Überladener Konstruktor
	: x(_x), y(_y)
{}
CPoint::~CPoint()						//Destruktor gibt den Speicherplatz des Objektes wieder frei
{}
void CPoint::setX(double _x) {
	x = _x;
};
void CPoint::setY(double _y) {
	y = _y;
};
double CPoint::getY(void) {
	return y;
};
double CPoint::getX(void) {
	return x;
};
double CPoint::getLength(void) {
	return  sqrt(pow(getX(), 2) + pow(getY(), 2));
};
ostream &operator<<(ostream &os, const CPoint &m) {
	return os << m.x << ", " << m.y;
}