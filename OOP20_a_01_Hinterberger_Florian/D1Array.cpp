#include <iostream>
#include <array>
#include <iterator>

using namespace std;
const size_t ELEMENTS = 24;

void coutArray(const array<double, ELEMENTS>& input)
{
	int column = 0;
	for(auto iter = input.begin(); iter != input.end(); ++iter)
	{
		cout << *iter << "  " << "\t\t";
		if ((++column) == 4)
		{
			cout << "\n";
			column = 0;
		}
	}
}

int main()
{
	//Old way
	double old_arr[ELEMENTS] = { 0 };
	for (size_t i = 0; i < sizeof(old_arr)/sizeof(double); i++)
	{
		old_arr[i] = (i+1) * 0.345678;
	}

	//new and better way
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
