#include "stdafx.h"
#include "Strecke.h"


CStrecke::CStrecke()
{
	start.setX(0);
	start.setY(0);
}


CStrecke::~CStrecke()
{
}

void CStrecke::addPunkt(CPunkt* _punkt)
{
	CPunkt* tmpPtr = NULL;
	for (tmpPtr = &start; tmpPtr->getNext() != NULL; tmpPtr = tmpPtr->getNext()) {
	}
	tmpPtr->setNext(_punkt);
}

void CStrecke::draw(CDC * pDC)
{
	CPunkt* tmpPtr = NULL;
	CPen Schwarz(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(&Schwarz);
	for (tmpPtr = &start; tmpPtr->getNext() != NULL; tmpPtr = tmpPtr->getNext()) {
		pDC->MoveTo((int)tmpPtr->getX(), (int)tmpPtr->getY());
		pDC->LineTo((int)tmpPtr->getNext()->getX(), (int)tmpPtr->getNext()->getY());
	}


}

double CStrecke::getLength(void)
{
	double length = 0;

	for (CPunkt* tmpPtr = &start; tmpPtr->getNext() != NULL; tmpPtr = tmpPtr->getNext()) {
	
		length += hypot(((tmpPtr->getNext())->getX() - tmpPtr->getX()), ((tmpPtr->getNext())->getY() - tmpPtr->getY()));
	}

	return length;
}
