#ifndef ColoredCylinder_H
#define ColoredCylinder_H

#include "ColoredThing.h"
#include "Cylinder.h"
#include <iostream>
#include <string>
#include <typeinfo>


class ColoredCylinder : public ColoredThing, public Cylinder {

public: 
	ColoredCylinder(double r, double h, double w, std::string c) 
		: Cylinder(r, h), ColoredThing(w, c) 
	{}

	double density() const { return weight / volume(); }
	

};


#endif