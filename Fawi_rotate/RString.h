#pragma once

#include <string>

class rStr {
private:
	int pos;
	std::string str;
public:
	rStr(std::string str);
	rStr operator++(int pos);
	rStr operator--(int pos);
	std::string umdrahn();
	void pos0(int rFlag);
	void pos1(int rFlag);
	void pos2(int rFlag);
	void pos3(int rFlag);
	int getpos() { return this->pos; }
	void setpos(int _pos) { this->pos = _pos; }
};