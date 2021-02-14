/*
    class: "USD.h"
    Description: This class creates the C2D class which is an base class of an USD class. It holds the exact same
    attributes with USD class but the conversion Factor attributes. By the attributes, this class can convert
    from USD to C2D or C2D to USD.
*/

#ifndef C2D_H
#define C2D_H
#include <string>
#include <iostream>
#include <cmath>
#include "USD.h"


class C2D : public USD
{
private:
    double converFactor; //1.36, to find C2D value from USD, divide converFactor from USD
    // to find the right c2d value. Else, to find the right USD currency from C2D value then multiply
    // converFactor to C2D value to get the right USD currency.

public:
    C2D();
    C2D(std::string n, int d, int w, double c);
    C2D(const C2D& other);
    ~C2D()
    {
        std::cout << "C2D Destructed!" << std::endl;
    };

    void setCon(double c);
    double getCon(); 

    //This function prints out the detail of the C2D object.
    //It overrides the print function from USD.
    void print() override
    {
        std::cout << "You have this amount of money in C2D: " << whole << "." << dec << std::endl;
        std::cout << "Your C2D to USD conversion factor is about " << converFactor << std::endl;
    };

    C2D U2C(USD m);
    USD C2U();

};


#endif
