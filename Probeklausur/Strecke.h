#pragma once
#include "stdafx.h"
#include "Punkt.h"


class CStrecke : public CPunkt
{
protected:
	CPunkt start;

public:
	CStrecke();
	~CStrecke();

	void addPunkt(CPunkt* _punkt);
	void draw(CDC* pDC);
	double getLength(void);
};

