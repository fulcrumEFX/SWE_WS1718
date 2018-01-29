#pragma once
class CPunkt
{
protected:
	double x, y;
	CPunkt* next;
public:
	CPunkt();
	CPunkt(double _x, double _y);
	~CPunkt();

	void setX(double _x);
	void setY(double _y);
	void setNext(CPunkt* _next);

	double getX();
	double getY();
	CPunkt* getNext();
};

