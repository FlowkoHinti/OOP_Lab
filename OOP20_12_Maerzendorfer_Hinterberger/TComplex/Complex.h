#pragma once
#include <string>

namespace HeeMan
{
	template<typename Sepp>
	class Complex
	{
	public:
		Complex();
		Complex(std::string s);

		~Complex();

		Complex<Sepp> operator+(Complex<Sepp>& c);
		Complex<Sepp> operator-(Complex<Sepp>& c);
		Complex<Sepp> operator*(Complex<Sepp>& c);
		Complex<Sepp>& operator=(const Complex<Sepp>& c);
		bool operator==(Complex<Sepp>& c);

		Sepp real{ 0 };
		Sepp imaginary{ 0 };
	};
}
