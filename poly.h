/*
 * poly.h
 *
 *  Created on: Nov 23, 2017
 *      Author: vitalik
 */

#ifndef POLY_H_
#define POLY_H_
#include "point.h"
#include "Point.cpp"
class Poly {
private:
	Point points[200];
	unsigned int size;
public:
	Poly();
	Poly(unsigned int N);
	unsigned int get_size() const;
	void set_size(unsigned int _count_);
	Point get_points(int i) const;
	Poly operator +(const Point &data) const;
	Poly& operator +=(const Point &data);

	Poly& operator =(const Poly &obj);
	void print() const;
	~Poly();
};

#endif /* POLY_H_ */
