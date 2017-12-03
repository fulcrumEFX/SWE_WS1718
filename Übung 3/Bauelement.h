#pragma once
#include "Punkt.h"

class CBauelement {
private:
	double kosten;
	CPointy position;
public:
	CBauelement(void);
	CBauelement(double _kosten, CPointy _position);
	~CBauelement(void);
	void setKosten(double _kosten);
	void setPosition(CPointy _position);
	double getKosten(void);
	CPointy getPosition(void);

};
