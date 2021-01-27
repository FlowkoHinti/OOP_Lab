#pragma once

#include "GeoRect.h"
#include "GeoTriangle.h"

class GeoHouse : public IGeomObj
{
public:
	GeoHouse(double rA, double rB, double tB, double tC)
		: r{ GeoRect(rA, rB) }, t{ GeoTriangle(rA, tB, tC) }{}

	void output() override;
	double circumference() override;
	double area() override;


protected:	GeoRect r{ GeoRect(0,0) };
	GeoTriangle t{ GeoTriangle(0,0,0) };

};

