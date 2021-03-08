/*
    class: "USD.h"
    Description: This class creates the USD class which is an base class of an C2D class.
    It holds the name of currency,the integer represents whole number of the amount of currency,
    and the integer represents the two deicmal places of the amount of currency.
*/

#ifndef USD_H
#define USD_H
#include <string>
#include <iostream>
#include <sstream>


class USD

{

protected:
    std::string name; //holds
    int dec;
    int whole;

public:
    // constructors
    USD();
    USD(std::string n, int d, int w);
    USD(const USD& other);
    ~USD()
    {
        std::cout << "USD Destructed!" << std::endl;
    };

    //setter and getters
    void setName(std::string name);
    void setDec(int dec);
    void setWhole(int whole);
    std::string getName();
    int getDec();
    int getWhole();

    //This function prints out the detail of the USD object.
    //It is an virtual function, which mean the derived object also has same type of function.
    virtual void print()
    {
        //std::cout << "You have this amount of money in " << name << ": " << whole << "." << dec << std::endl;
        std::cout << "$" << whole << "." << dec;
    };
    
    std::string toString() {
        std::stringstream dollar;
        dollar << "$" << whole << "." << dec;
        return dollar.str();
    }

    //operator overloading func; -, -= , =
    USD& operator=(const USD& other);
    USD operator+(USD other);
    USD& operator-=(const USD& other);

    bool operator==(const USD& other) const;
    bool operator!=(const USD& other) const;

    bool operator<=(const USD& m1);
    bool operator>(const USD& m1);
};


#endif
