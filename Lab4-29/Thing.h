
#ifndef THING_H
#define THING_H

#include <iostream>
#include <string>
#include <typeinfo>


class Thing {

public:

	std::string name() const {
		std::string n = typeid(*this).name();

		#ifdef _MSC_VER
				n = n.substr(6);
		#else 
				n = n.substr(n.find_first_not_of("123456789"));
		#endif 

		return n;

	}

	virtual ~Thing() = 0;

};

#endif