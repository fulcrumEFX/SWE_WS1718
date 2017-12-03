#pragma once
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
	void setName(string _name);
	double getPrice(void);
	CPointy getPosition(void);
	string getName(void);
	void print(void);

};