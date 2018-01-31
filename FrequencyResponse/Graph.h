#pragma once
#include "Point.h"
#include "LinkedList.h"


#define LEFT_MARGIN 20				//Offset from Window border
#define UPPER_MARGIN 16				
#define X_OFFSET 230				//Offset from left side of the Window
#define FRAME_SPACING 10			//Space between both Frames of Bode Diagram
#define FRAME_HEIGHT 200			//Frame Height
#define FRAME_WIDTH 570				//Frame Width
#define Y_AXIS_X_OFFSET 10			//Offset Y-Axis in x direction from Frame
#define Y_AXIS_Y_OFFSET 10			//Offset Y-Axis from top+bottom of Frame
#define X_AXIS_LENGTH FRAME_WIDTH-(2*Y_AXIS_Y_OFFSET)		//lenght of x-axis in px for array creation (one datapoint per px)
#define COLOR_BLACK RGB(0,0,0)
#define COLOR_RED RGB(0xFF, 0, 0)

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

	void draw(CDC* pDC, CLinkedList & _componentList);
	void drawFrame(CDC* pDC, CPoint _start) const;
	void drawDataPoint(CDC* pDC, double _frequency, double _value);

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

