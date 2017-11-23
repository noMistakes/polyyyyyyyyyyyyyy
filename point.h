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
	void set_x(double _x);
	void set_y(double _y);
	double get_x();
	double get_y();
	Point operator +(Point &data);
	Point& operator +=(Point $data);
	Point operator -(Point &data);
	Point& operator -=(Point $data);
};