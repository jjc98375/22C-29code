#ifndef COLOREDRECTANGULARPRISM_H
#define COLOREDRECTANGULARPRISM_H

#include "ColoredThing.h"
#include "RectangularPrism.h"
#include <iostream>
#include <string>
#include <typeinfo>


class ColoredRectangularPrism : public ColoredThing, public RectangularPrism {

public:
	ColoredRectangularPrism(double l, double wi, double h, double w, std::string c)
		: RectangularPrism(l, wi, h), ColoredThing(w, c)
	{}

	double density() const { return weight / volume(); }


};



#endif