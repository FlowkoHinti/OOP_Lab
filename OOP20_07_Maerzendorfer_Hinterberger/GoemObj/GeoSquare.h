#pragma once
#include "GeoRect.h"
#include "IUniqueID.h"

class GeoSquare : public GeoRect, virtual public Counter
{
	GeoSquare(double x) : GeoRect(x,x){}

	void output() override;
};

