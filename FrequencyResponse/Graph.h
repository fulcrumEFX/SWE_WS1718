#pragma once
#include "Point.h"

#define LEFT_MARGIN 20
#define UPPER_MARGIN 16

class CGraph
{
private:
	int height;
	int width;
	CPoint origin;
	CPoint start;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
public:
	CGraph();
	~CGraph();

	void draw(CDC* pDC);

	void setHeight(int _height);
	void setWidth(int _width);
	void setOrigin(CPoint _org);
	void setStart(CPoint _start);
	void setXmin(int _x_min);
	void setXmax(int _x_max);
	void setYmin(int _y_min);
	void setYmax(int _y_max);

	int getHeight() const;
	int getWidth() const;
	CPoint getOrigin() const;
	CPoint getStart() const;
	int getXmin() const;
	int getXmax() const;
	int getYmin() const;
	int getYmax() const;
	
	
	
};

