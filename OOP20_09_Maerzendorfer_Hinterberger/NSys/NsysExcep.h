#pragma once
#include <exception>

class NsysExcep :
	public std::exception
{
	public:
	virtual const char* what() const
	{
		return "An exception in Nsys happened :-(\n      .\n   __/ \\__\n   \\     /\n   /.'o'.\\  \n    .o.'.\n   .'.'o'.\n  o'.o.'.o.\n .'.o.'.'.o.\n.o.'.o.'.o.'.\n   [_____]\n    \\___/ ";
	}
};

