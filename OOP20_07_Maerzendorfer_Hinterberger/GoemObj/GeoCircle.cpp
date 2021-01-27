#define _USE_MATH_DEFINES
#include "GeoCircle.h"
#include <iostream>
#include <math.h>

double GeoCircle::circumference() {
    return 2 * M_PI * r;
}

double GeoCircle::area() {
    return M_PI * r * r;
}

void GeoCircle::output() {
    std::cout << "Circle: " << std::endl << "Circumference: " << circumference() << std::endl << "Area: " << area() << std::endl;
}