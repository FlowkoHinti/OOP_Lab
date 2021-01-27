#include "Complex.h"
#include <vector>
#include <iomanip>

Complex::Complex()
{
}

Complex::~Complex()
{
}

Complex::Complex(std::string s)
{
	char op{ '\0' };
	if (s.rfind("+") != std::string::npos) op = '+';
	else if (s.rfind("-") != std::string::npos)op = '-';
	else return;

	const std::string real = s.substr(0, s.rfind(op));
	const std::string img = s.substr(s.rfind(op), s.length() - s.rfind(op) - 1);
	
	this->imaginary = stoi(img);
	this->real = stoi(real);
}

Complex Complex::operator+(Complex& c)
{
	Complex r;
	r.real = this->real + c.real;
	r.imaginary = this->imaginary + c.imaginary;
	return r;
}

Complex Complex::operator-(Complex& c)
{
	Complex r;
	r.real = this->real - c.real;
	r.imaginary = this->imaginary - c.imaginary;
	return r;
}
Complex Complex::operator*(Complex& c)
{
	Complex r;
	r.real = this->real * c.real + (this->imaginary * c.imaginary * -1);
	r.imaginary = this->real * c.imaginary + this->imaginary * c.real;
	return r;
}