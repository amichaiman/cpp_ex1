#ifndef _MATRIX_H
#define _MATRIX_H
#include <iostream>
#include "complex.h"

using namespace std;

class Matrix
{
public:
    Matrix(const int theSize, const string theName);    //c'tor
    Matrix(const int theSize);                          //c'tor
    void setName(const string theName){name = theName;}
    string getName() const {return name;}
    int getSize() const {return size;}
    void setValue(const int i,const int j,const Complex c); //puts c in matrix[i][j] 
    Matrix *multByScalar(const Complex c);          //returns matrix multiplyed by c
    Matrix *raiseToThePower(const int n);           //returns matrix raised to the n'th power
    void iMatrix();         //changes matrix value to the "i" matrix
    Matrix *multMatrix(Complex** m1,Complex **m2);  //returns matrix witch is the result of m1 multiplyed by m2
    Complex getComplex(const int i,const int j) const;  //returns complex at matrix[i][j]
    void print() const; //prints matrix to screen
    Complex **getMatrix() const;        
    Complex computeDet(const int n,Complex **m);    //computes determinant
 
private:
    int size;
    Complex **matrix;
    string name;
};


#endif
