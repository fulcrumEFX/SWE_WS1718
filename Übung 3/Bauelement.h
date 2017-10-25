#pragma once
#include "Punkt.h"

class CBauelement {
private:
	double kosten;
	CPunkt position;
public:
	CBauelement(void);
	CBauelement(double _kosten, CPunkt _position);
	~CBauelement(void);
	void setKosten(double _kosten);
	void setPosition(CPunkt _position);
	double getKosten(void);
	CPunkt getPosition(void);

};
