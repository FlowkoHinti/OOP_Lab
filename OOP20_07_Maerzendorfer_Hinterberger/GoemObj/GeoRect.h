#pragma once
#include "IGeomObj.h"
#include <iostream>
#include "IUniqueID.h"

class GeoRect : public IGeomObj, virtual public Counter
{
public:
	GeoRect(double x, double y) :a(x), b(y) {
		this->ID = Counter::getID();
	}

	void output() override;
	double  circumference() override;
	double  area() override;
	double getA() const;

protected:
	double a{ 0 }, b{ 0 };
	unsigned int ID;
};

