#pragma once

class CPointy {
private:
	double x;
	double y;
public:
	CPointy(void);					//Konstruktor
	CPointy(double _x, double _y);	//Überladener Konstruktor
	~CPointy(void);					//Destruktor
	void setX(double _X);
	void setY(double _Y);
	double getX(void);
	double getY(void);
	double getLength(void);
	
};


