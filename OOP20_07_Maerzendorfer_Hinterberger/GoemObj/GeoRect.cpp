#include "GeoRect.h"
#include <iostream>


double  GeoRect::circumference()
{
	return 2 * a + 2 * b;
}
double  GeoRect::area()
{
	return a * b;
}

void GeoRect::output()
{
	std::cout << "Rectangle: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}
double GeoRect::getA() const{
	return this->a;
}
