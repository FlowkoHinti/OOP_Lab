#include <iostream>
#include "IGeomObj.h"
#include "GeoCircle.h"
#include "GeoContainer.h"
#include "GeoEllipse.h"
#include "GeoRect.h"
#include "GeoSquare.h"
#include "GeoTriangle.h"
#include "IUniqueID.h"
#include "GeoHouse.h"

//class test1 {
//public:
//	void virtual print() = 0;
//};

//class test2 : public test1 {
//public:
//	void print() override {
//		std::cout << "print on test 2 was called" << std::endl;
//	}
//};

//class test3 : public test1 {
//public:
//	void print() override {
//		std::cout << "print on test 3 was called" << std::endl;
//	}
//};

unsigned int Counter::seed = 0;

int main() {

	GeoEllipse ge(5,4);
	GeoTriangle gr(3, 3, 3);
	GeoContainer gc;
	gc.addGeoObj(&ge);
	gc.addGeoObj(&gr);
	gc.output();
	GeoHouse Haus{ 2,2,2,2 };
	Haus.output();
	//gc.removeGeoObj(&ge);

	//std::shared_ptr<test1> t2 = std::make_shared<test2>();
	//std::shared_ptr<test1> t3 = std::make_shared<test3>();

	////should print t2
	//t2->print();
	////shoul print t3
	//t3->print();


	//copy-const does not seem to make any sense in this scenario

}