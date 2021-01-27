#pragma once
#include "IGeomObj.h"
#include <vector>
class GeoContainer :
    public IGeomObj
{
public:
	GeoContainer() = default;
	void output() override;
	double  circumference() override;
	double  area() override;
	void addGeoObj(IGeomObj* obj);
	void removeGeoObj(IGeomObj* obj);
	IGeomObj* getGeoObj() const;
protected:
	std::vector<IGeomObj*> container;
};

