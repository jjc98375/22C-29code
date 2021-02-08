
#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "GeometricSolid.h"
#include <iostream>
#include <string>
#include <typeinfo>


class Circular: public GeometricSolid {

protected: 
	double radius;

public:
	Circular(double r) { radius = r; }

};



#endif
