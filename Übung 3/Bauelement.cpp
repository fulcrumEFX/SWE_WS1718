#include "stdafx.h"
#include "Punkt.h"
#include "Bauelement.h"


CBauelement::CBauelement()
	: kosten(0), position()
{}
CBauelement::CBauelement(double _kosten, CPunkt _position)
	: kosten(_kosten), position(_position)
{}

CBauelement::~CBauelement(void)
{}
void CBauelement::setKosten(double _kosten)
{
	kosten = _kosten;
}
void CBauelement::setPosition(CPunkt _position)
{
	position = _position;
}
double CBauelement::getKosten(void)
{
	return kosten;
}
CPunkt CBauelement::getPosition(void)
{
	return position;
}
