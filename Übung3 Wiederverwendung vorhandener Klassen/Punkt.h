#pragma once

class CPunkt {
private:
	double x;
	double y;
public:
	CPunkt(void);					//Konstruktor
	CPunkt(double _x, double _y);	//Überladener Konstruktor
	~CPunkt(void);					//Destruktor
	void setX(double _X);
	void setY(double _Y);
	double getX(void);
	double getY(void);
	double getLength(void);
};


