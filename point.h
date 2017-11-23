#pragma once
#include <iostream>
using namespace std;
class Point
{
private:
	double x, y;
public:
	Point();
	Point(double _x, double _y);
	void setX(double _x);
	void setY(double _y);
	double getX();
	double getY();
	Point operator +(Point &in);
	Point& operator +=(Point &in);
	Point operator -(Point &in);
	Point& operator -=(Point &in);
};