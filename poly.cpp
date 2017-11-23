#include "poly.h"
#include <iostream>

using namespace std;

Poly::Poly():size(0) {

}
Poly::Poly(unsigned int N) {

	size = N;
	double x, y;

	for (int i = 0; i < N; i++) {
		cout << "x" << i + 1 << ": ";
		cin >> x;
		cout << "y" << i + 1 << ": ";
		cin >> y;
		points[i] = Point(x, y);
	}

}

unsigned int Poly::get_size() const {
	return size;
}

void Poly::set_size(unsigned int _size) {
	size = _size;
}

Point Poly::get_points(int i) const {
	return points[i];
}

Poly& Poly::operator =(const Poly &obj) {
	for (int i = 0; i < size; i++) {
		points[i] = obj.get_points(i);

	}
	return *this;
}

Poly Poly::operator +(const Point &obj) const {
	Poly poly(*this);
	for (int i = 0; i < size; i++) {
		double x = obj.getX() + data;
		double y =  obj.getY() + data;
		Poly(x, y);
	}
	return poly;
}

Poly& Poly::operator +=(const Point &obj) {
	for (int i = 0; i < size; i++) {
		Poly poly(*this);
		double x = obj.getX() + data;
		double y = data.getY() + data;
		Poly(x, y);
	}
	return *this;
}

Poly::~Poly() {
}
