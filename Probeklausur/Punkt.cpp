#include "stdafx.h"
#include "Punkt.h"


CPunkt::CPunkt():
	CPunkt(0.0, 0.0)
{
	
}

CPunkt::CPunkt(double _x, double _y)
	: x(_x), y(_y), next(nullptr)
{
	
}


CPunkt::~CPunkt()
{
}

void CPunkt::setX(double _x)
{
	x = _x;
}

void CPunkt::setY(double _y)
{
	y = _y;
}

void CPunkt::setNext(CPunkt * _next)
{
	next = _next;
}

double CPunkt::getX()
{
	return x;
}

double CPunkt::getY()
{
	return y;
}

CPunkt * CPunkt::getNext()
{
	return next;
}
