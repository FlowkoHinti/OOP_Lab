#include <iostream>
#include <array>
#include <algorithm>
#include <exception>
#include <string>
#include <sstream>


template <typename T>
T convert_to(const std::string& str)
{
	std::istringstream ss(str);
	T num;
	ss >> num;
	return num;
}

template<typename T>
std::string TTrunc(T a, int b){
	int c;
	if (std::is_arithmetic<T>::value)
	{
		std::string number = std::to_string(a);
		size_t length = number.length();

		if (std::is_integral_v<T>)
		{
			//int/char/...
			if (b == length) return number;
			else if (b > length)
			{
				//padden
				for (length; length < b; ++length)
				{
					number = "0" + number;
				}
				return number;
			}
			else
			{
				//cut
				return number.substr(length - b, length);
			}

		}
		else
		{
			//float/...
			c = number.find('.');
			if (b == c) return number;
			else if (b > c)
			{
				//padden
				for (c; c < b; ++c)
				{
					number = "0" + number;
				}
				return number;
			}
			else
			{
				//cut
				return number.substr(c - b, length);
			}
			
		}

	}
	else throw std::invalid_argument("Not a Number");

}

template<typename T>
T TRound(T a, int b)
{
	if (std::is_arithmetic<T>::value)
	{
		std::string number = std::to_string(a);
		int c = 0;

		if (std::is_integral_v<T>)
		{
			//int/char/...
			 c = number.length() - 1;
		}
		else
		{
			//float/double/...
			 c = number.find(".");
		}

		//b filtern
		c = c - b;

		if (number[c] >= '5' || number[c]=='.')
		{
			//aufrunden
			++number[c - 1];
			
		}
		//set other digits to zero
		for (int i = c; i < number.length(); ++i)
		{
			if (number[i] != '.') number[i] = '0';
		}
		return convert_to<T>(number);

	}
	else throw std::invalid_argument("Not a Number");
}

template<typename T, typename K>
int SizeCompare(T a, K b)
{
	if (sizeof(a) > sizeof(b)) return 1;
	if (sizeof(b) > sizeof(a)) return -1;
	return 0;
}
template<typename T>
bool Swap3(T& a, T& b, T& c) {

	if (std::is_arithmetic<T>::value)
	{
		bool r = false;
		if (b > a)
		{
			std::swap(a, b);
			r = true;
		}
		if (c > a)
		{
			std::swap(a, c);
			r = true;
		}
		if (c > b)
		{
			std::swap(c, b);
			r = true;
		}
		return r;
	}
	else
	{
		throw std::invalid_argument("Wrong Typing");
	}
}

template<typename T>
std::array<T, 3> sortThree(T a, T b, T c)
{
	if (std::is_arithmetic<T>::value)
	{
		std::array<T, 3> exportArr = { a, b, c };
		std::sort(exportArr.begin(), exportArr.end(), std::greater<T>());
		return exportArr;
	}
	else
	{
		throw std::invalid_argument("Wrong Typing");
	}


}

int main()
{
	try
	{
		std::array<float, 3> Yeet = sortThree(1.2f, 3.4f, 9.69420f);
		//std::array<const char*, 3> Yeet2 = sortThree("kasper", "huber", "sepp");

		double a = 24;
		double b = 13;
		double c = 2;
		bool Feet = Swap3(a, b, c);

		float d = 32;

		int i = SizeCompare(a, d);


		int t = 323;
		double s = 15.34632;
		
		t = TRound(t, 0);
		s = TRound(s, 0);

		std::string test = TTrunc(t, 2);
		std::string test1 = TTrunc(t, 8);
		std::string test2 = TTrunc(s, 2);
		std::string test3 = TTrunc(s, 20);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Datentyp nicht moeglich mehr info: " << e.what() << std::endl;
	}





}
