#pragma once

#include <string>
#include <iostream>
#include <map>
#include <assert.h>
#include "NsysExcep.h"


class Nsys
{
	unsigned long val{ 0 };
	unsigned short base{ 10 };

public:
	Nsys()=default;
	Nsys(unsigned long v, unsigned short b) :val(v), base(b) 
	{
		assert(v >= 0);
		assert(b >= 0 && b <= 36);
	};
	virtual ~Nsys()=default;

	std::string toString() const;
	void parse(std::string& s);

	Nsys operator+(const Nsys& n);
	Nsys operator++(int); //postfix
	Nsys& operator++();	//prefix
	Nsys& operator+=(const Nsys& n);
	Nsys operator-(const Nsys& n);
	Nsys operator--(int); //postfix
	Nsys& operator--();	//prefix
	Nsys& operator-=(const Nsys& n);
	Nsys operator*(const Nsys& n);
	Nsys& operator*=(const Nsys& n);
	Nsys operator/(const Nsys& n);
	Nsys& operator/=(const Nsys& n);
	Nsys& operator<<(unsigned int i);
	Nsys& operator>>(unsigned int i);

	Nsys& operator=(Nsys& n);
	Nsys& operator=(int i);

	operator int();


	unsigned long getVal() const
	{
		return val;
	}
	unsigned short getBase() const
	{
		return base;
	}
	void setVal(long v)
	{
		val = v;
	}
	void setBase(unsigned short b)
	{
		base = b;
	}
};


class Nsys2 : public Nsys {
public:
	Nsys2(unsigned long val = 0) : Nsys(val, 2) 
	{}
};


class Nsys8 : public Nsys
{
	public:
	Nsys8(unsigned long val=0): Nsys(val,8)
	{}
};

class Nsys10 : public Nsys
{
public:
	Nsys10(unsigned long val=0): Nsys(val, 10)
	{}
};

class Nsys16 : public Nsys
{
public:
	Nsys16(unsigned long val=0): Nsys(val,16)
	{}

};
