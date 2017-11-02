#pragma once
#include "Punkt.h"

class CBauelement {
private:
	double kosten;
	CPoint position;
public:
	CBauelement(void);
	CBauelement(double _kosten, CPoint _position);
	~CBauelement(void);
	void setKosten(double _kosten);
	void setPosition(CPoint _position);
	double getKosten(void);
	CPoint getPosition(void);

};
