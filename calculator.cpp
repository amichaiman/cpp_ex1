#include <iostream>
using namespace std;

class Complex
{
public:
    Complex():a(0),b(0){}
    Complex(float x):a(x),b(0){}
    Complex(float x, float y):a(x),b(y){}
    void SetA(float x){ a = x;}
    void SetB(float y){ b = y;}
    void SetAB(float x,float y){ a = x; b = y;}
    void print(){cout << a << "+" << b << "*i" << endl; }
private:
    float a,b;
};


class Matrix
{
public:
    Matrix()size(0){}
    Matrix(int theSize):size(theSize)m(new Complex[size][size]){}
    void setName(char *theName){ strcpy(name,theName); }
    void setValues();
private:
    int size;
    Complex **m;
    int name;
};

Matrix::setValues()
{
    int i,j;
    
    for(i=0; i<size; i++)
        for(j=0;j<size; j++)
        {
            cout << i << "," << j << ":";
            cin >> m[i][j];
        }
}

int main()
{
    
    
}
