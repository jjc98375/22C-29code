#ifndef ColoredSphere_H
#define ColoredSphere_H

#include "ColoredThing.h"
#include "Sphere.h"
#include <iostream>
#include <string>
#include <typeinfo>


class ColoredSphere : public ColoredThing, public Sphere {

public:
	ColoredSphere(double r, double w, std::string c)
		: Sphere(r), ColoredThing(w, c)
	{}

	double density() const { return weight / volume(); }


};



#endif#pragma once
