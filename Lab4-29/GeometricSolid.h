#ifndef GEOMETRICSOLID_H
#define GEOMETRICSOLID_H

#include "Thing.h"
#include <iostream>
#include <string>
#include <typeinfo>


class GeometricSolid : virtual public Thing {

public:
	~GeometricSolid() {};

	virtual double volume() const = 0; //declare pure virtual function, volume()

};

#endif
