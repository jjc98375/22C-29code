#ifndef COLOREDTHING_H
#define COLOREDTHING_H

#include "Thing.h"
#include <iostream>
#include <string>
#include <typeinfo>


class ColoredThing : virtual public Thing {

protected:
	double weight;
	std::string color;

public:
	~ColoredThing() {}
	ColoredThing(double w, std::string c) { weight = w; color = c;}

	virtual double density() const = 0; //declare pure virtual function, density()
										//density = ??

};

#endif
#pragma once
