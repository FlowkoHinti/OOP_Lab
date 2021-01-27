#include <iostream>
#include "Nsys.h"
#include "NsysExcep.h"

std::ostream& operator<<( std::ostream& stream, const Nsys& n)
{
stream << n.toString();
return stream;
}

std::istream& operator>>( std::istream& stream, Nsys& n)
{
	std::string x;
	stream >> x;
	n.parse(x);
	return stream;
}

void foo(int test)
{
	//do something
}

int main()
{
	try
	{
		Nsys n1{ 320, 30 };
		Nsys n2{ 12, 16 };
		Nsys n3{ 90, 2 };
		Nsys n4 = n1 + n3;
		n4 += n1;
		n4 /= n2;

		++n3;
		--n4;

		Nsys8 n5;
		//std::cin >> n5;
		//std::cout << n4 << std::endl;

		n1.operator<<(3);

		foo(n1);

		NsysExcep e{};
		throw e;
	}
	catch(NsysExcep& e)
	{
		std::cout<<e.what()<<std::endl;
	}

}