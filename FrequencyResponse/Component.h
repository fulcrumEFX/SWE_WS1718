#pragma once
#include "stdafx.h"
#include "DisplayValue.h"
#include "Point.h"
#include "Complex.h"



class CComponent {
protected:
	double price;
	CPointy position;
	std::string name;
	CDisplayValue* displayValPtr;
	int _unitIndex;
public:
	CComponent(void);
	CComponent(double _price, CPointy _position);
	CComponent(double _price, CPointy _position, std::string _name);
	~CComponent(void);
	void setPrice(double _price);
	void setPosition(CPointy _position);
	void setName(std::string _name);
	void setDisplayVal(CDisplayValue* _ptr);
	void setUnitIndex(int _index);
	CDisplayValue* getDisplayVal(void);
	int getUnitIndex(void);
	double getPrice(void);
	CPointy getPosition(void);
	std::string getName(void);
	
	CString getDisplayValueAsC_Str(int _index, double _value);
	virtual double getReal(void)=0;
	virtual double getImag(double _omega)=0;
	virtual void setValue(double _val) = 0;
	virtual double getValue(void) = 0;
	
};