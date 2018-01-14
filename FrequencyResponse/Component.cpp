#include "stdafx.h"
#include "Component.h"

CComponent::CComponent()
	: price(0), position(CPointy(0, 0)), name()
{}
CComponent::CComponent(double _price, CPointy _position, std::string _name)
	: price(_price), position(_position), name(_name)
{}
CComponent::CComponent(double _price, CPointy _position)
	: price(_price), position(_position)
{}
CComponent::~CComponent(void)
{
	
}
void CComponent::setPrice(double _price)
{
	price = _price;
}
void CComponent::setName(std::string _name)
{
	name = _name;
}
void CComponent::setPosition(CPointy _position)
{
	position = _position;
}
double CComponent::getPrice(void)
{
	return price;
}
CPointy CComponent::getPosition(void)
{
	return position;
}

std::string CComponent::getName(void)
{
	return name;
}

void CComponent::setDisplayVal(CDisplayValue * _ptr)
{
	displayValPtr = _ptr;
	
}

void CComponent::setUnitIndex(int _index)
{
	_unitIndex = _index;
}

CDisplayValue * CComponent::getDisplayVal(void)
{
	return displayValPtr;
}

int CComponent::getUnitIndex(void)
{
	return _unitIndex;
}

CString CComponent::getDisplayValueAsC_Str(int _index, double _value)
{
	return displayValPtr->getDisplayValueAsCString(_index, _value);
}

