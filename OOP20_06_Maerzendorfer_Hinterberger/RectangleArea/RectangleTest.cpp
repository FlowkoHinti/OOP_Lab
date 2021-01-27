#include "Rectangle.h"

int main()
{
	//Declare a RectangleArea object
	RectangleArea r_area;

	//read the widht and height
	r_area.readInput();

	//print the width and height
	r_area.Rectangle::display();

	//print the area
	r_area.display();

	Equilateral e;
	e.Triangle::display();
	e.Isosceles::display();
	e.display();

	return 0;

}


