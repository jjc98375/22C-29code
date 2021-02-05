#include "USD.h"

//setters and getters
void USD::setName(std::string name) { this->name = name; }
void USD::setDec(int dec) { this->dec = dec; }
void USD::setWhole(int whole) { this->whole = whole; }
std::string USD::getName() { return name; }
int USD::getDec() { return dec; }
int USD::getWhole() { return whole; }


// This function is a base constructor of USD class.
// Pre: None
// Post: dec and whole will be all zero, and the name attributes would become "USD"
// Return: None
USD::USD()
{
    name = "USD";
    dec = 0;
    whole = 0;
}

// This function is a base constructor of USD class but with arguments
// Pre: one string and two integers
// Post: all the name, dec, whole attributes would assign the given parameter value.
// Return: None
USD::USD(std::string n, int d, int w)
{
    name = n;
    dec = d;
    whole = w;
}

// This function is a copy constructor of USD class.
// Pre: constant referenced USD object
// Post: copy all attributes from other class
// Return: None
USD::USD(const USD& other)
{
    name = other.name;
    dec = other.dec;
    whole = other.whole;
}

// This function is an overloaded operator which represents ==. By this function, program can check either
// two USD classes are same.
// Pre: constant referenced USD object
// Post: compare each attributes and decide whether it is true or not.
// Return: boolean
bool USD::operator==(const USD& other) const
{
    return whole == other.whole && dec == other.dec;
}

// This function is an overloaded operator which represents !=. By this function, program can check either
// two USD classes are not same.
// Pre: constant referenced USD object
// Post: compare each attributes and decide whether it is true or not.
// Return: boolean
bool USD::operator!=(const USD& other) const
{
    return !(*this == other);
}

// This function is an overloaded operator which represents <. By this function, program can check whether 'this'
// class is smaller than the parameter object.
// Pre: constant referenced USD object
// Post: compare each attributes and decide whether it is true or not.
// Return: boolean
bool USD::operator<=(const USD& m1)
{
    if (*this > m1) {
        return false;
    }
    else {
        return true;
    }
}

// This function is an overloaded operator which represents >. By this function, program can check whether 'this'
// class is greater than the parameter object.
// Pre: constant referenced USD object
// Post: compare each attributes and decide whether it is true or not.
// Return: boolean
bool USD::operator>(const USD& m1)
{
    return (whole > m1.whole) || (whole == m1.whole && dec > m1.dec);
}

/*
This function is an overloaded operator which represents =. By this function, it assigns two different object
that shares the same class.
pre: receives USD class argument as referenced constant, since the program not modifying the parameter.
post: copy all attributes from other object
Return: referenced USD
*/
USD& USD::operator=(const USD& other)
{
    name = other.name;
    dec = other.dec;
    whole = other.whole;
    return *this;
};

/*
This function is an overloaded operator represents +. By this, program can add the USD classes or objects.
pre: USD other should be legal USD class
post: A new USD class that has been created returned after it gets the instances
Return: USD
*/
USD USD::operator+(USD other)
{
    USD new_money;
    new_money.dec = dec + other.dec;
    if (new_money.dec > 100)
    {
        new_money.whole += 1;
        new_money.dec = new_money.dec % 100;
    }
    new_money.whole = new_money.whole + whole + other.whole;
    return new_money;
}

/*
pre: receives USD class argument as referenced constant, since the program not modifying the parameter.
post: function first check the condition of the other's value to see if the input USD class's value
     is greater than the containing USD value. Then, it succesfully subtracts the numerical value
     of USD class and return the result back to the function holder.
Return: Referenced USD
*/
USD& USD::operator-=(const USD& other)
{
    if (whole < other.whole)
    {
        std::cout << "You have out of balance" << std::endl;
    }
    else if (whole == other.whole && dec < other.dec)
    {
        std::cout << "You have out of balance" << std::endl;
    }

    if (dec < other.dec)
    {
        whole--;
        dec += 100;
    }
    dec -= other.dec;
    whole -= other.whole;
    return *this;
}