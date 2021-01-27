#include "GeoContainer.h"
#include <iostream>

double  GeoContainer::circumference()
{
	double c{ 0 };
	for (size_t i = 0; i < container.size(); ++i) 
	{
		c += container[i]->circumference();
	}
	return c;
}
double  GeoContainer::area()
{
	double area{ 0 };
	for (size_t i = 0; i < container.size(); ++i) {
		area += container[i]->circumference();
	}
	return area;
}

void GeoContainer::output()
{
	std::cout << "GeoContainer: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}

void GeoContainer::addGeoObj(IGeomObj* obj)
{
	container.push_back(obj);
}
void GeoContainer::removeGeoObj(IGeomObj* obj)
{
	for (auto it = container.begin(); it != container.end(); ++it)
	{
		if (*it == obj) 
		{
			container.erase(it); 
			return;
		}
	}
}
