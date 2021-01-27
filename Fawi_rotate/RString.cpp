
#include <string>
#include <array>
#include "RString.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm> 

rStr::rStr(std::string str) :pos(0), str(str) {}
std::string rStr::umdrahn() {
	std::string str = this->str;
	 /*char revChr[this->str.length+1];

	for (int i = this->str.length-1;i >= 0;i--) {
		revChr[this->str.length - 1 - i] = this->str[i];
	}
	revChr[this->str.length] = '\0';
	std::string revStr = revChr;*/

	reverse(str.begin(), str.end());
	
	return str;
}

rStr rStr::operator++(int pos) {
	system("CLS");
	if (this->pos == 7) {
		this->pos = 0;
	}
	else {
		this->pos = (this->pos + 1);
	}
	switch (this->pos)
	{
	case(0):
		pos0(0);
		break;
	case(1):
		this->pos1(0);
		break;
	case(2):
		this->pos2(0);
		break;
	case(3):
		this->pos3(0);
		break;
	case(4):
		this->pos0(1);
		break;
	case(5):
		this->pos1(1);
		break;
	case(6):
		this->pos2(1);
		break;
	case(7):
		this->pos3(1);
		break;
	default:
		break;
	}

	return *this;
}

rStr rStr::operator--(int pos) {
	system("CLS");
	if (this->pos == 0) {
		this->pos = 7;
	}
	else {
		this->pos = (this->pos - 1);
	}
	switch (this->pos)
	{
	case(0):
		pos0(0);
		break;
	case(1):
		this->pos1(0);
		break;
	case(2):
		this->pos2(0);
		break;
	case(3):
		this->pos3(0);
		break;
	case(4):
		this->pos0(1);
		break;
	case(5):
		this->pos1(1);
		break;
	case(6):
		this->pos2(1);
		break;
	case(7):
		this->pos3(1);
		break;
	default:
		break;
	}

	return *this;
}

void rStr::pos0(int rFlag = 0) {
	std::string str;
	if (rFlag) {
		str = this->umdrahn();
	}
	else {
		str = this->str;
	}
	int len = str.length();
	int dist;
	if (len % 2 == 1) {
		dist = (len - 1) / 2;
	}
	else {
		dist = len / 2;
	}
	for (int i = 0;i < dist;i++) {
		std::cout << "\n";
	}
	std::cout << str;
	if (rFlag) {
		str = this->umdrahn();
	}
}
void rStr::pos1(int rFlag = 0) {
	if (!rFlag) {
		str = this->umdrahn();
	}
	else {
		str = this->str;
	}
	int len = str.length();
	for (int i = 0;i < len;i++) {
		int dist = len-i-1;
		for (int k=0;k <dist;k++) {
			std::cout << " ";
		}
		std::cout << str[i];
		std::cout << "\n";
	}
	if (!rFlag) {
		str = this->umdrahn();
	}
}
void rStr::pos2(int rFlag = 0) {
	if (!rFlag) {
		str = this->umdrahn();
	}
	else {
		str = this->str;
	}
	int len = str.length();
	int dist;
	if (len % 2 == 1) {
		dist = (len - 1) / 2;
	}
	else {
		dist = len / 2;
	}
	for (int i = 0;i < len;i++) {
		for (int k = 0;k < dist;k++) {
			std::cout << " ";
		}
		std::cout << str[i];
		std::cout << "\n";
	}
	if (!rFlag) {
		str = this->umdrahn();
	}
}
void rStr::pos3(int rFlag = 0) {
	if (!rFlag) {
		str = this->umdrahn();
	}
	else {
		str = this->str;
	}
	int len = str.length();
	for (int i = 0;i < len;i++) {
		int dist = i;
		for (int k= 0;k<dist ;k++) {
			std::cout << " ";
		}
		std::cout << str[i];
		std::cout << "\n";
	}
	if (!rFlag) {
		str = this->umdrahn();
	}
}