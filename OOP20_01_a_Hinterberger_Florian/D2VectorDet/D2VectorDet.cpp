#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>


using namespace std;

vector <string> split(string & to_split, char delimiter)
{
	vector <string> split_vec;
	size_t delim_ind = 0;
	size_t old_ind = 0;
	delim_ind = to_split.find(delimiter, old_ind);
	while (delim_ind != string::npos)
	{
		split_vec.push_back(to_split.substr(old_ind, (delim_ind-old_ind)));
		old_ind = delim_ind + 1;
		delim_ind = to_split.find(delimiter, old_ind);
	}
	split_vec.push_back(to_split.substr(old_ind, (to_split.length() - old_ind)));
	return split_vec;
}

double determinant(vector<vector<double>> & matrix_in)
{
	return
		matrix_in[0][0] * matrix_in[1][1] * matrix_in[2][2] +
		matrix_in[0][1] * matrix_in[1][2] * matrix_in[2][0] +
		matrix_in[0][2] * matrix_in[1][0] * matrix_in[2][1] -

		matrix_in[2][0] * matrix_in[1][1] * matrix_in[0][2] -
		matrix_in[2][1] * matrix_in[1][2] * matrix_in[0][0] -
		matrix_in[2][2] * matrix_in[1][0] * matrix_in[0][1];
	
}

void print_mat_det(vector<vector<double>> matrix_in, double det_in)
{
	
	for (size_t row = 0; row < matrix_in.size(); ++row)
	{
		if (row == 0) cout << "\t";
		if(row == 1) cout << "    det ";
		if (row == 2) cout << "\t";
		cout << "[ ";
		for (size_t col = 0; col < matrix_in[row].size(); ++col)
		{
			cout << matrix_in[row][col] << " ";
		}
		
		if (row == 1) cout << "] = " << setprecision(4) << det_in << endl;
		else cout << "]" << endl;
	}
}


int main(int argc, char* argv[])
{
	vector<vector<double>> matrix;


	ifstream read_stream(argv[1]);
	if (read_stream.is_open())
	{
		string line;
		size_t row_cnt = 0;
		while (getline(read_stream, line))
		{

			vector<string> row = split(line, ',');
			vector<double> row_double;
			for (auto iter = row.begin(); iter != row.end(); ++iter)
			{
				row_double.push_back(stod(*iter));
			}
			matrix.push_back(row_double);

		}
		print_mat_det(matrix, determinant(matrix));


	}
	else cerr << "Could not open file!";


}