#pragma once

class CPoint {
private:
	double x;
	double y;
public:
	CPoint(void);					//Konstruktor
	CPoint(double _x, double _y);	//Überladener Konstruktor
	~CPoint(void);					//Destruktor
	void setX(double _X);
	void setY(double _Y);
	double getX(void);
	double getY(void);
	double getLength(void);
};


