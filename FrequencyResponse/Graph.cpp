#include "stdafx.h"
#include "Graph.h"

CGraph::CGraph()
{
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

void CGraph::setOrigin(CPointy _org)
{
	origin = _org;
}

void CGraph::setStart(CPointy _start)
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

void CGraph::draw() {
	CWnd* targetWindow;

}