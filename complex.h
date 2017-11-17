#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;
class Complex
{
public:
    Complex(const float theReal,const float  theImg):real(theReal),img(theImg){}    //c'tor
    Complex():real(0),img(0){}             //default c'tor
    Complex add(const Complex &c) const;    //addition of two complex numbers
    Complex sub(const Complex c) const;     //substition of two complex numbers
    Complex mul(const Complex c) const;     ////multipication of two complex numbers
    float getReal() const;            
    float getImg() const;
    void setReal(const float theReal);
    void setImg(const float theImg);
    void print();                       //print complex as (real,img)
    bool parseComplex(string comp);     //parse values from string. returns true if values are legal, false otherwise
private:
    float real;
    float img;
};


#endif
