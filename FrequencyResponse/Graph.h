#pragma once
#include "Point.h"

#define LEFT_MARGIN 30
#define UPPER_MARGIN 30

class CGraph
{
private:
	int height;
	int width;
	CPointy origin;
	CPointy start;
	int x_min;
	int x_max;
	int y_min;
	int y_max;
public:
	CGraph();
	~CGraph();

	void draw();

	void setHeight(int _height);
	void setWidth(int _width);
	void setOrigin(CPointy _org);
	void setStart(CPointy _start);
	void setXmin(int _x_min);
	void setXmax(int _x_max);
	void setYmin(int _y_min);
	void setYmax(int _y_max);
	
	
	
};

