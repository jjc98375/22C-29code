#pragma once

#ifndef Cube_H
#define Cube_H

#include "RectangularPrism.h"
#include <iostream>
#include <string>
#include <typeinfo>


class Cube : public RectangularPrism {

public:
	Cube(double side) : RectangularPrism(side, side, side) {}
	//double volume() const { return length *  * side; }

};



#endif
