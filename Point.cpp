#include <iostream>
#include "point.h"
using namespace std;
Point::Point()
{

}
Point::Point(double _x, double _y)
{
	x = _x;
	y = _y;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setX(double _x)
{
	x = _x;
}
void Point::setY(double _y)
{
	y = _y;
}
Point Point::operator+(Point &in)
{
	Point temp(*this);

	temp.setX(temp.getX() + in.getX());
	temp.setX(temp.getY() + in.getX());

	return temp;

}
Point& Point::operator+=(Point &in)
{
	x +=in.getX();
	y +=in.getY();

	return *this;
}
