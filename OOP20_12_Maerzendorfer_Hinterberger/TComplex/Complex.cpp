#include "Complex.h"
#include <vector>
#include <iomanip>
#include <exception>

using namespace HeeMan;

template<typename Sepp>
Complex<Sepp>::Complex()
{
}
template<typename Sepp>
Complex<Sepp>::~Complex()
{
}
template<typename Sepp>
Complex<Sepp>::Complex(std::string s)
{
	char op{ '\0' };
	if (s.rfind("+") != std::string::npos) op = '+';
	else if (s.rfind("-") != std::string::npos)op = '-';
	else return;

	const std::string real = s.substr(0, s.rfind(op));
	const std::string img = s.substr(s.rfind(op), s.length() - s.rfind(op) - 1);
	try {
		if (std::is_floating_point_v<Sepp>)
		{
			this->imaginary = stold(img);
			this->real = stold(real);
		}
		else if(std::is_integral_v<Sepp>)
		{
			this->imaginary = stoll(img);
			this->real = stoll(real);
		}
		else{
			throw std::invalid_argument("non numeric data type!");
		}
	}catch(std::exception e){
		e.what();
	}
}
template<typename Sepp>
Complex<Sepp> Complex<Sepp>::operator+(Complex<Sepp>& c)
{
	Complex<Sepp> r;
	r.real = this->real + c.real;
	r.imaginary = this->imaginary + c.imaginary;
	return r;
}
template<typename Sepp>
Complex<Sepp> Complex<Sepp>::operator-(Complex<Sepp>& c)
{
	Complex<Sepp> r;
	r.real = this->real - c.real;
	r.imaginary = this->imaginary - c.imaginary;
	return r;
}
template<typename Sepp>
Complex<Sepp> Complex<Sepp>::operator*(Complex<Sepp>& c)
{
	Complex<Sepp> r;
	r.real = this->real * c.real + (this->imaginary * c.imaginary * -1);
	r.imaginary = this->real * c.imaginary + this->imaginary * c.real;
	return r;
}
template<typename Sepp>
Complex<Sepp>& Complex<Sepp>::operator=(const Complex<Sepp>& c)
{
	this->real = c.real;
	this->imaginary = c.imaginary;
	return *this;
}
template<typename Sepp>
bool Complex<Sepp>::operator==(Complex<Sepp>& c)
{
	if (this->real == c.real && this->imaginary == c.imaginary) return true;
	else return false;
}