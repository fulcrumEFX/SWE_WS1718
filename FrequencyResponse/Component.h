#pragma once
#include "stdafx.h"
#include "Point.h"
#include "Complex.h"



class CComponent {
protected:
	double price;
	CPointy position;
	std::string name;
public:
	CComponent(void);
	CComponent(double _price, CPointy _position);
	CComponent(double _price, CPointy _position, std::string _name);
	~CComponent(void);
	void setPrice(double _price);
	void setPosition(CPointy _position);
	void setName(std::string _name);
	double getPrice(void);
	CPointy getPosition(void);
	std::string getName(void);
	virtual double getReal(void)=0;
	virtual double getImag(double _omega)=0;
	virtual void setValue(double _val) = 0;
	virtual double getValue(void) = 0;
};