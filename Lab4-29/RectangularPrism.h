#pragma once

#ifndef RectangularPrism_H
#define RectangularPrism_H

#include "GeometricSolid.h"
#include <iostream>
#include <string>
#include <typeinfo>


class RectangularPrism : public GeometricSolid {

protected:
	double length, width, height;

public:
	RectangularPrism(double l, double w, double h) { length = l;  width= w;  height = h; }
	double volume() const { return length * height * width; }

};



#endif
