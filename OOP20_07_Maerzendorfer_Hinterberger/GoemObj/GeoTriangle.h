#pragma once

#include "IGeomObj.h"
#include "IUniqueID.h"

class GeoTriangle : public IGeomObj, virtual public Counter
{
public:
	GeoTriangle(double a, double b, double c);
	void output() override;
	double circumference() override;
	double  area() override;

protected:
	double a{ 0 }, b{ 0 }, c{ 0 };
	unsigned int ID;
};

