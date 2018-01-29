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
	
	setStart(getOrigin() + CPoint(X_OFFSET, 0));
	drawFrame(pDC, getStart());
	drawFrame(pDC, getStart() + CPoint(0, FRAME_HEIGHT + FRAME_SPACING));

	CPen penBlack;
	penBlack.CreatePen(PS_SOLID, 1, COLOR_BLACK);
	pDC->SelectObject(&penBlack);
		
}

void CGraph::drawFrame(CDC* pDC, CPoint _start) const
{
	CSize FrameSize(FRAME_WIDTH, FRAME_HEIGHT);
	CRect Frame(_start, FrameSize);
	pDC->Rectangle(&Frame);

	CPoint referencePoint = _start + CPoint(Y_AXIS_X_OFFSET, (FrameSize.cy / 2));
	pDC->MoveTo(referencePoint);
	pDC->LineTo(referencePoint + CPoint(FrameSize.cx - 2 * Y_AXIS_X_OFFSET, 0));
	pDC->MoveTo(_start + CPoint(Y_AXIS_X_OFFSET, Y_AXIS_Y_OFFSET));
	pDC->LineTo(_start + CPoint(Y_AXIS_X_OFFSET, FRAME_HEIGHT - Y_AXIS_Y_OFFSET));
}


