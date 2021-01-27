#pragma once
#include "GeoCircle.h"
#include "IUniqueID.h"

class GeoEllipse : public IGeomObj, virtual public Counter
{
public:
	GeoEllipse(double x, double y) :a(x), b(y) {
		this->ID = Counter::getID();
	};
	void output() override;
	double  circumference() override;
	double area() override;
protected:
	double a = 0, b = 0;
	unsigned int ID;
};

