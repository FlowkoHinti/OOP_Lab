#include "GeoHouse.h"



double  GeoHouse::circumference() 
{
	return  t.circumference()  + r.circumference() - 2*r.getA();
}
double  GeoHouse::area()  
{
	return t.area() + r.area();
}

void GeoHouse::output() 
{
	std::cout << "House: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}