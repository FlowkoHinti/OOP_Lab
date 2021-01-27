#include "GeoTriangle.h"
#include <iostream>
#include <math.h>


GeoTriangle::GeoTriangle(double a, double b, double c)
{
	this->ID = Counter::getID();
	if (a > b + c) return;
	if (b > a + c) return;
	if (c > a + b) return;
	this->a = a;
	this->b = b;
	this->c = c;

}

void GeoTriangle::output()
{
	std::cout << "Triangle: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}
double GeoTriangle::circumference()
{
	return a + b + c;
}
double GeoTriangle::area()
{
	return (sqrtl((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b)) / 4);
}