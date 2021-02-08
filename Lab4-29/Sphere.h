

#ifndef Sphere_H
#define Sphere_H

#define _USE_MATH_DEFINES

#include "Circular.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <math.h>

class Sphere : public Circular {

public:
	Sphere(double r) : Circular(r) {}
	double volume() const { return 4/3 * radius * radius * radius * M_PI; };

};


#endif