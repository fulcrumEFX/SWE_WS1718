 #pragma once

class CComplex
{
private:
	double real;
	double imag;
	double angle;
	double absolute;
	friend ostream &operator<<(ostream &, CComplex const&);
public:
	CComplex(double _real, double _imag);
	CComplex();
	~CComplex();
	double getReal(void) const;
	double getImag(void) const;
	double getAngle(void) const;
	double getAbsolute(void) const;
	void setReal(double _real);
	void setImag(double _imag);
	void setAngle(double _angle);
	void setAbsolute(double _absolute);
	CComplex CComplex::operator+(const CComplex _c);
	CComplex CComplex::operator-(const CComplex _c);
	CComplex CComplex::operator*(const CComplex _c);
	CComplex CComplex::operator/(const CComplex _c);
};

