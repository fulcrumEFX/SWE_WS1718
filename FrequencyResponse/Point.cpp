#include "stdafx.h"
#include "Point.h"

CPointy::CPointy()						//Der Konstruktor Initialisiert automatisch die Attribute 
	: x(0), y(0)						//beim Anlegen einer Klasse
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
	return  std::sqrt(std::pow(getX(), 2) + pow(getY(), 2));
}
CPointy CPointy::operator+(const CPointy & _p)
{
	CPointy _point;
	_point.x = this->x + _p.x;
	_point.y = this->y + _p.y;
	
	return _point;
}
;
