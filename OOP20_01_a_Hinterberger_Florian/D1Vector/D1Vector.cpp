#include<iostream>
#include<fstream>
#include<vector>
#include<string>


using namespace std;


void write_file(const vector <string> arguments_in)
{
	ofstream file_stream("out.txt");
	if (file_stream.is_open())
	{
		file_stream << "Programmname=" << arguments_in[0] << endl <<
			"Argumente=" << arguments_in.size() - 1 << "\n";
		int i = 1;
		for (auto iterator = arguments_in.begin() + 1; iterator != arguments_in.end(); ++iterator, ++i)
		{
			file_stream << "Argument_" << i << "=" << *iterator << endl;
		}
		file_stream.close();
	}


}

int main(int argc, char* argv[])
{
	vector <string> arguments_vec;

	for (int i = 0; i < argc; ++i)
	{
		arguments_vec.push_back(argv[i]);
	}

	write_file(arguments_vec);
}