#include "stdafx.h"
#include "Graph.h"

CGraph::CGraph()
{
	this->setOrigin(CPoint(LEFT_MARGIN, UPPER_MARGIN));
}

CGraph::~CGraph()
{
}

void CGraph::setHeight(int _height)
{
	height = _height;
}

void CGraph::setWidth(int _width)
{
	width = _width;
}

void CGraph::setOrigin(CPoint _org)
{
	origin = _org;
}

void CGraph::setStart(CPoint _start)
{
	start = _start;
}

void CGraph::setXmin(int _x_min)
{
	x_min = _x_min;
}

void CGraph::setXmax(int _x_max)
{
	x_max = _x_max;
}

void CGraph::setYmin(int _y_min)
{
	y_min = _y_min;
}

void CGraph::setYmax(int _y_max)
{
	y_max = _y_max;
}

int CGraph::getHeight() const
{
	return height;
}

int CGraph::getWidth() const
{
	return width;
}

CPoint CGraph::getOrigin() const
{
	return origin;
}

CPoint CGraph::getStart() const
{
	return start;
}

int CGraph::getXmin() const
{
	return x_min;
}

int CGraph::getXmax() const
{
	return x_max;
}

int CGraph::getYmin() const
{
	return y_min;
}

int CGraph::getYmax() const
{
	return y_max;
}

void CGraph::draw(CDC* pDC) {
	CPen penBlack;
	penBlack.CreatePen(PS_SOLID, 1, RGB(0,0,0));

	this->setStart(this->getOrigin() + CPoint(230, 0));
	CSize FrameSize(570, 400);
	CRect Frame(this->getStart(), FrameSize);

	pDC->Rectangle(&Frame);		//Draw Frame
	pDC->SelectObject(&penBlack);
	
	//Divide into 2 Diagrams
	CPoint oldPoint = this->getStart() + CPoint(0, (FrameSize.cy / 2));
	pDC->MoveTo(oldPoint);
	pDC->LineTo(oldPoint + CPoint(FrameSize.cx, 0));
	//Draw bae of Diagrams

	

}