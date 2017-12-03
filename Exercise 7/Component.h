#pragma once
#include "stdafx.h"
#include "Point.h"
#include "Complex.h"


class CComponent {
protected:
	double price;
	CPointy position;
	string name;
public:
	CComponent(void);
	CComponent(double _price, CPointy _position, string _name);
	~CComponent(void);
	void setPrice(double _price);
	void setPosition(CPointy _position);
	double getPrice(void);
	CPointy getPosition(void);
	string getName(void);
	virtual double getReal(void)=0;
	virtual double getImag(double _omega)=0;
};