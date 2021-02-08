#ifndef COLOREDCUBE_H
#define COLOREDCUBE_H

#include "ColoredThing.h"
#include "Cube.h"
#include <iostream>
#include <string>
#include <typeinfo>


class ColoredCube: public ColoredThing, public Cube {

public:
	ColoredCube(double side, double w, std::string c)
		: Cube(side), ColoredThing(w, c)
	{}

	double density() const { return weight / volume(); }


};



#endif