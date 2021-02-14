#include "USD.h"
#include "C2D.h"

//setters and getters of converFactor which not inherited from Base class instances
void C2D::setCon(double c) { converFactor = c; }
double C2D::getCon() { return converFactor; }

// Pre: new C2D object has been created without the parameters
// Post: all the instances of new C2D object has been initialized with default values.
C2D::C2D() {
    name = "C2D";
    dec = 0;
    whole = 0;
    converFactor = 1.36;
}

// Pre: new C2D object has been created, but with parameter of all instances that need
// Post: all the instances of new C2D object has been initialized with the given parameters.
C2D::C2D(std::string n, int d, int w, double c) {
    name = n;
    dec = d;
    whole = w;
    converFactor = c;
}

// Pre: new C2D object has been created with the actual class parameter
// Post: all the instances of new C2D object has been initialized by copying the instance from 'other' class
C2D::C2D(const C2D& other)
{
    name = other.name;
    dec = other.dec;
    whole = other.whole;
    converFactor = other.converFactor;
}

/*
U2C() stand as USD to C2D which already indicates the direction of the conversion.
This is one of the conversion function from C2D class.
Pre: USD object
Post: Create the C2D object and restore the corresponding data from parameter m by using
    the conversion factor.
return: C2D
*/
C2D C2D::U2C(USD m)
{
    C2D c2d;
    double d_val = m.getDec() * 0.01;
    int w_val = m.getWhole();
    double val = w_val + d_val;
    val = val / c2d.getCon();
    w_val = (int)floor(val);
    c2d.setWhole(w_val);
    val = val - w_val;
    c2d.setDec((int)round(val * 100));
    return c2d;
}

/*
C2U() stand as C2D to USD which already indicates the direction of the conversion.
This is one of the conversion function from C2D class.
Pre: C2D object
Post: Create the USD object and restore the corresponding data from parameter m by using
    the conversion factor.
return: USD
*/
USD C2D::C2U()
{
    USD usd;
    double d_val = this->getDec() * 0.01;
    int w_val = this->getWhole();
    double val = w_val + d_val;
    val = val * this->getCon();
    w_val = (int)floor(val);
    usd.setWhole(w_val);
    val = val - w_val;
    usd.setDec((int)round(val * 100));
    return usd;
}

