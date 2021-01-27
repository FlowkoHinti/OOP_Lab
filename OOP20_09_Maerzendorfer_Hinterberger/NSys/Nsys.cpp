#include "Nsys.h"
#include <math.h>


static std::map<char, long> Char2Val
{
	std::make_pair('0', 0l),
	std::make_pair('1', 1l),
	std::make_pair('2', 2l),
	std::make_pair('3', 3l),
	std::make_pair('4', 4l),
	std::make_pair('5', 5l),
	std::make_pair('6', 6l),
	std::make_pair('7', 7l),
	std::make_pair('8', 8l),
	std::make_pair('9', 9l),
	std::make_pair('A', 10l),
	std::make_pair('B', 11l),
	std::make_pair('C', 12l),
	std::make_pair('D', 13l),
	std::make_pair('E', 14l),
	std::make_pair('F', 15l),
	std::make_pair('G', 16l),
	std::make_pair('H', 17l),
	std::make_pair('I', 18l),
	std::make_pair('J', 19l),
	std::make_pair('K', 20l),
	std::make_pair('L', 21l),
	std::make_pair('M', 22l),
	std::make_pair('N', 23l),
	std::make_pair('O', 24l),
	std::make_pair('P', 25l),
	std::make_pair('Q', 26l),
	std::make_pair('R', 27l),
	std::make_pair('S', 28l),
	std::make_pair('T', 29l),
	std::make_pair('U', 30l),
	std::make_pair('V', 31l),
	std::make_pair('W', 32l),
	std::make_pair('X', 33l),
	std::make_pair('Y', 34l),
	std::make_pair('Z', 35l),
};

static const std::map<long, char> Val2Char
{
	std::make_pair(0l, '0'),
	std::make_pair(1l, '1'),
	std::make_pair(2l, '2'),
	std::make_pair(3l, '3'),
	std::make_pair(4l, '4'),
	std::make_pair(5l, '5'),
	std::make_pair(6l, '6'),
	std::make_pair(7l, '7'),
	std::make_pair(8l, '8'),
	std::make_pair(9l, '9'),
	std::make_pair(10l, 'A'),
	std::make_pair(11l, 'B'),
	std::make_pair(12l, 'C'),
	std::make_pair(13l, 'D'),
	std::make_pair(14l, 'E'),
	std::make_pair(15l, 'F'),
	std::make_pair(16l, 'G'),
	std::make_pair(17l, 'H'),
	std::make_pair(18l, 'I'),
	std::make_pair(19l, 'J'),
	std::make_pair(20l, 'K'),
	std::make_pair(21l, 'L'),
	std::make_pair(22l, 'M'),
	std::make_pair(23l, 'N'),
	std::make_pair(24l, 'O'),
	std::make_pair(25l, 'P'),
	std::make_pair(26l, 'Q'),
	std::make_pair(27l, 'R'),
	std::make_pair(28l, 'S'),
	std::make_pair(29l, 'T'),
	std::make_pair(30l, 'U'),
	std::make_pair(31l, 'V'),
	std::make_pair(32l, 'W'),
	std::make_pair(33l, 'X'),
	std::make_pair(34l, 'Y'),
	std::make_pair(35l, 'Z')
};

std::string Nsys::toString() const{
	std::string s{""};
	long r = val;
	
	while(r>0){
		
		s += Val2Char[(long)(r % base)];
		r /= base;
	}
	return s;
}

void Nsys::parse(std::string& s) 
{
	long r{ 0 };
	for (size_t index = 0; index < s.length(); ++index)
	{
		r += Char2Val[toupper(s[index])] * (unsigned long)powl((long double)this->getBase(), (long double)s.length()-index-1);
		
	}
	this->setVal(r);
}

Nsys Nsys::operator+(const Nsys& n) 
{
	Nsys re;
	
	re.val=this->val+n.val;
	re.base=this->base;
	return re;
}

Nsys Nsys::operator++(int) 
{
	Nsys temp=*this;
	++*this;
	return temp;
}
Nsys& Nsys::operator++() 
{
	val++;
	return *this;
}
Nsys& Nsys::operator+=(const Nsys& n) 
{
 	this->val+=n.val;
	return *this;
}
Nsys Nsys::operator-(const Nsys& n) 
{
	NsysExcep execep;
	if(n.val>this->val) throw execep;
	
	Nsys re;
	
	re.val=this->val-n.val;
	re.base=this->base;
	return re;
}
Nsys& Nsys::operator--() 
{
	this->val--;
	return *this;
}

Nsys Nsys::operator--(int){
	Nsys temp=*this;
	--*this;
	return temp;
}

Nsys& Nsys::operator-=(const Nsys& n) 
{
	NsysExcep execep;
	if(n.val>this->val) throw execep;
	this->val-=n.val;
	return *this;
}
Nsys Nsys::operator*(const Nsys& n)
{
	Nsys re;
	
	re.val=(this->val)*(n.val);
	re.base=this->base;
	return re;
}
Nsys& Nsys::operator*=(const Nsys& n) 
{
	(this->val)*=(n.val);
	return *this;
}
Nsys Nsys::operator/(const Nsys& n) 
{
	Nsys re;
	
	re.val=this->val/n.val;
	re.base=this->base;
	return re;
}
Nsys& Nsys::operator/=(const Nsys& n) 
{
	this->val /= n.val;
	return *this;
}

Nsys& Nsys::operator<<(unsigned int i) 
{
	for (size_t j = 0; j < i; ++j)
	{
		this->val *= 2;
	}
	return *this;
}
Nsys& Nsys::operator>>(unsigned int i)
{
	for (size_t j = 0; j < i; ++j)
	{
		this->val /= 2;
	}
	return *this;
}
Nsys& Nsys::operator=(Nsys& n)
{
	if(this!=&n)
	{
		this->val=n.val;
	}
	return *this;
}
Nsys& Nsys::operator=(int i)
{
	this->val=i;
	return *this;
}

Nsys::operator int()
{
	return (int)this->val;
}

