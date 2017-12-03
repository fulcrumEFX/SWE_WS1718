#pragma once
#include "Point.h"

class CVector
{
private:
	CPointy p1;
	CPointy p2;
	friend ostream &operator<<(ostream &os, const CVector _v);
public:
	CVector();
	CVector(CPointy _p1, CPointy _p2);
	~CVector();
	CVector CVector::operator+(CVector _v);
};

