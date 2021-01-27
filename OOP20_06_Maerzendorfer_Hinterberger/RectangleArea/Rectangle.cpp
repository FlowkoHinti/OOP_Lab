#include "Rectangle.h"
#include <iostream>


void Rectangle::display()
{
	std::cout << "h=" << this->hoehe << " b=" << this->breite << std::endl;
}

void RectangleArea::display()
{
	std::cout << "h=" << this->hoehe << " b=" << this->breite << " A="<< (this->breite * this->hoehe)<< std::endl;
}

void RectangleArea::readInput()
{
	double b = 0, h = 0;
	std::cout << "Bitte Breite angeben:" << std::endl;
	while (b < 1 || b > 100)
	{
		std::cin >> b;
		if (b < 1 || b > 100) std::cerr << "Die Breite kann nicht < 1 oder > als 100 sein!" << std::endl;
	}
	this->breite = b;

	std::cout << "Bitte Hoehe angeben:" << std::endl;
	while (h < 1 || h > 100)
	{
		std::cin >> h;
		if (h < 1 || h > 100) std::cerr << "Die Hoehe kann nicht < 1 oder > als 100 sein!" << std::endl;
	}
	this->hoehe = h;
}

Triangle::Triangle() = default;
void Triangle::display()
{
	std::cout << "I am a Triangle!" << std::endl;
}


Isosceles::Isosceles() = default;
void Isosceles::display()
{
	std::cout << "I am a Croissant based on a Triangle!" << std::endl;
	Triangle::display();
}

Equilateral::Equilateral() = default;
void Equilateral::display() 
{
	std::cout << "I am an equilateral triangle based on a Croissant!" << std::endl;
	Isosceles::display();
}
