#define _USE_MATH_DEFINES
#include "GeoEllipse.h"
#include <iostream>
#include <math.h>

double  GeoEllipse::circumference()
{
    return 2*M_PI *sqrtl((a*a+b*b)/2);
}
double  GeoEllipse::area()
{
    return M_PI * a * b;
}

void GeoEllipse::output()
{
    std::cout << "Ellipse: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}