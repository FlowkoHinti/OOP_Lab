#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, string argv[])
{
	vector <string> arguments_vec(argc);

	for (auto iter = arguments_vec.begin(); iter != arguments_vec.end(); ++iter)
	{
		std::cout << *iter << "\n";
	}

}