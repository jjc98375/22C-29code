
#ifndef CYLINDER_H
#define CYLINDER_H

#define _USE_MATH_DEFINES

#include "Circular.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <math.h>

class Cylinder : public Circular {

protected:
	double height;

public:
	Cylinder(double r, double h) : Circular(r) { height = h; }
	double volume() const { return (height * radius * radius) * M_PI; }

};



#endif