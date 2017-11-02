#include "stdafx.h"
#include "Vector.h"

CVector::CVector()
	: p1(0, 0), p2(0, 0)
{}
CVector::CVector(CPoint _p1, CPoint _p2)
	: p1(_p1), p2(_p2)
{}
CVector::~CVector()
{}

CVector CVector::operator+(CVector _v)
{
	CVector res;
	res.p1.setX(p1.getX() + _v.p1.getX());
	res.p1.setY(p1.getY() + _v.p1.getY());
	res.p2.setX(p2.getX() + _v.p2.getX());
	res.p2.setY(p2.getY() + _v.p2.getY());
	return res;
}
ostream &operator<<(ostream &os, const CVector _v)
{
	return os << "(" << _v.p1 << "), (" << _v.p2 << ")";
}
