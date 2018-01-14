#include "stdafx.h"
#include "Complex.h"

CComplex::CComplex(double _real, double _imag)
	: real(_real), imag(_imag)
{}
CComplex::CComplex()
	: real(0), imag(0)
{}
CComplex::~CComplex()
{}
double CComplex::getReal(void) const
{
	return real;
}
double CComplex::getImag(void) const
{
	return imag;
}
double CComplex::getAngle(void) const
{
	return std::atan2(real, imag);
}
double CComplex::getAbsolute(void) const
{
	return std::sqrt(real*real + imag*imag);
}
void CComplex::setAngle(double _angle)
{
	angle = _angle;
}
void CComplex::setAbsolute(double _absolute)
{
	absolute = _absolute;
}
void CComplex::setReal(double _real)
{
	real = _real;
}
void CComplex::setImag(double _imag)
{
	imag = _imag;
}
CComplex CComplex::operator+(const CComplex _c)
{
	CComplex res;
	res.real = real + _c.real;
	res.imag = imag + _c.imag;
	return res;
}
CComplex CComplex::operator-(const CComplex _c)
{
	CComplex res;
	res.real = real - _c.real;
	res.imag = imag - _c.imag;
	return res;
}
CComplex CComplex::operator*(const CComplex _c) {
	CComplex res;
	res.real = (real*_c.real) - (imag*_c.imag);
	res.imag = (imag*_c.real) - (real*_c.imag);
	return res;
}
CComplex CComplex::operator/(const CComplex _c){
	CComplex res;
	res.real = ((real*_c.real) + (imag*_c.imag)) / ((_c.real*_c.real) + (_c.imag*_c.imag));
	res.imag = ((imag*_c.real) - (real*_c.imag)) / ((_c.real*_c.real) + (_c.imag*_c.imag));
	return res;
}

CComplex CComplex::getInverse(void) const
{
	return CComplex((real / ((real * real) + (imag * imag))),((-1 * imag) / ((real * real) + (imag * imag))));
}
