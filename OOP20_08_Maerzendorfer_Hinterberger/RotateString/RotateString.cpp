#include <string>
#include <iostream>
#include <iomanip>

inline std::string& operator<<(std::string& s, int i){
	i = i % s.length();
	rotate(s.begin(), s.begin() + i, s.end());
	return s;
}

inline std::string& operator>>(std::string& s, int i){
	i = i % s.length();
	rotate(s.begin(), s.end() - i, s.end());
	return s;
}

int main(){
	std::string input = "LET IT SNOW";
	std::cout << std::quoted(input << 3) << '\n'; // " IT SNOWLET"
	input = "LET IT SNOW";
	std::cout << std::quoted(input >> 10) << '\n'; // "ET IT SNOWL"
	return 0;
}