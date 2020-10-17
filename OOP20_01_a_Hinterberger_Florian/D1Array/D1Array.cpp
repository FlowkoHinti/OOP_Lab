#include <iostream>
#include <iomanip>
#include <array>
#include <iterator>

using namespace std;
const size_t ELEMENTS = 23;

void coutArray(const array<double, ELEMENTS> & input)
{
	int column = 0;
	
	for(auto iter = input.begin(); iter != input.end(); ++iter)
	{
		cout << setprecision(5) << *iter << "\t";
		if ((++column) == 4)
		{
			cout << "\n";
			column = 0;
		}
	}
}

int main()
{
	array <double, ELEMENTS> class_arr;
	class_arr.fill(0);

	int ind = 1;
	for (auto i = class_arr.begin(); i != class_arr.end(); i++, ind++)
	{
		*i = ind * 0.345678;
	}
	coutArray(class_arr);
	
	return true;
}

