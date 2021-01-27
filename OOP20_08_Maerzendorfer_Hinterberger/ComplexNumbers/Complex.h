#pragma once
#include <string>
class Complex
{
public:
	Complex();
	Complex(std::string s);

	~Complex();

	Complex operator+(Complex& c);
	Complex operator-(Complex& c);
	Complex operator*(Complex& c);


	int real{ 0 }, imaginary{ 0 };
};

