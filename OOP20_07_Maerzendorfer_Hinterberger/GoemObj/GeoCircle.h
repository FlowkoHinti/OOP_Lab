#pragma once
#include "IGeomObj.h"
#include "IUniqueID.h"

class GeoCircle : public IGeomObj, virtual public Counter
{
public:
	GeoCircle(double x) :r(x) {
		this->ID = Counter::getID();
	}

	void output() override;
	double circumference() override;
	double  area() override;
protected:
	double r = 0;
	unsigned int ID;
};
