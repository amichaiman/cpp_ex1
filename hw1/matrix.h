#ifndef _MATRIX_H
#define _MATRIX_H
#include <iostream>
#include "complex.h"

using namespace std;

class Matrix
{
public:
    Matrix(int theSize, string theName);
    Matrix(int theSize);
    void setName(string theName){name = theName;}
    string getName(){return name;}
    int getSize(){return size;}
    void setValue(int i, int j, Complex c);
    Matrix *multByScalar(Complex c);
    Matrix *raiseToThePower(int n);
    void iMatrix();
    Matrix *multMatrix(Complex** m1, Complex **m2);
    Complex getComplex(int i,int j);
    void print();
    Complex **getMatrix();
    Complex computeDet(int n,Complex **m);
 
private:
    int size;
    Complex **matrix;
    string name;
};


#endif
