#include "Complex.h"
#include <string>
#include <iostream>

inline std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.real << (c.imaginary > 0 ? " + " : " ") << c.imaginary << "i";
	return os;
}
inline std::istream& operator>>(std::istream& is, Complex& c) {
	is >> c.real >> c.imaginary;
	return is;
}

int main()
{
	std::string s1{ "" }, s2{ "" };
	std::cin >> s1;
	std::cin >> s2;

	Complex x(s1), y(s2);
	Complex z = x + y;
	Complex w;
	std::cin >> w;
	std::cout <<"x: "<< x << std::endl;
	std::cout <<"y: "<< y << std::endl;
	std::cout <<"z=x+y: "<< z << std::endl;
	std::cout <<"w: "<< w << std::endl;

}