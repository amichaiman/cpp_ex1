#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Complex
{
public:
    Complex(float theReal, float theImg):real(theReal),img(theImg){}
    Complex():real(0),img(0){}
    Complex add(Complex &c);
    Complex sub(Complex c);
    Complex mul(Complex c);
    float getReal();
    float getImg();
    void setReal(float theReal);
    void setImg(float theImg);
    void print();
    bool parseComplex(string comp);
private:
    float real;
    float img;
};


#endif
