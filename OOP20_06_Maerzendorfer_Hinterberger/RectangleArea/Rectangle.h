#pragma once

class Rectangle
{
public:
	void display();

protected:
	double hoehe{ 0 };
	double breite{ 0 };

};

class RectangleArea : public Rectangle
{
public:
	void display();
	void readInput();

};

class Triangle
{
public:
	Triangle();
	void display();
};

class Isosceles : public Triangle
{
public:
	Isosceles();
	void display();
};

class Equilateral : public Isosceles
{
public:
	Equilateral();
	void display();
};