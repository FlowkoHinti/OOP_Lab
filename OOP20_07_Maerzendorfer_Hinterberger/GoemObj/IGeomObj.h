#pragma once

class IGeomObj 
{
public:
	void virtual output()=0;
	double virtual circumference() = 0;
	double virtual area() = 0;
};