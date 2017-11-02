#pragma once
#include "Point.h"

class CComponent {
protected:
	double price;
	CPoint position;
	string name;
public:
	CComponent(void);
	CComponent(double _price, CPoint _position, string _name);
	~CComponent(void);
	void setPrice(double _price);
	void setPosition(CPoint _position);
	void setName(string _name);
	double getPrice(void);
	CPoint getPosition(void);
	string getName(void);
	void ausgabe(void);

};