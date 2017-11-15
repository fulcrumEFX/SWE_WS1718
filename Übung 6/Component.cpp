#include "stdafx.h"
#include "Component.h"

CComponent::CComponent()
	: price(0), position(CPoint(0, 0)), name()
{}
CComponent::CComponent(double _price, CPoint _position, string _name)
	: price(_price), position(_position), name(_name)
{}
CComponent::~CComponent(void)
{}
void CComponent::setPrice(double _price)
{
	price = _price;
}
void CComponent::setPosition(CPoint _position)
{
	position = _position;
}
void CComponent::setName(string _name)
{
	cout << "Component name: ";
	cin >> _name;
}
double CComponent::getPrice(void)
{
	return price;
}
CPoint CComponent::getPosition(void)
{
	return position;
}

string CComponent::getName(void)
{
	return name;
}
void CComponent::print(void)
{
	cout << "Component name: " << name;
	cout << ", Price: " << price << "Euro";
	cout << ", Position: " << position << endl;
}
