#pragma once
#include "Point.h"

class CVector
{
private:
	CPoint p1;
	CPoint p2;
	friend ostream &operator<<(ostream &os, const CVector _v);
public:
	CVector();
	CVector(CPoint _p1, CPoint _p2);
	~CVector();
	CVector CVector::operator+(CVector _v);
};

