#include "matrix.h"



Matrix::Matrix(int theSize, string theName)
:size(theSize),name(theName)
{
    matrix = new Complex *[size];
    
    for (int i=0; i<size; i++)
        matrix[i] = new Complex[size];
}

Matrix::Matrix(int theSize)
:size(theSize)
{
    matrix = new Complex *[size];
    
    for (int i=0; i<size; i++)
        matrix[i] = new Complex[size];
}


void Matrix::setValue(int i, int j, Complex c)
{
    matrix[i][j] = c;
}

Matrix *Matrix::multByScalar(Complex c)
{
    Matrix *m = new Matrix(size);
    
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            m->setValue(i,j,matrix[i][j].mul(c));
        
    return m;
}

Matrix *Matrix::raiseToThePower(int n)
{
    Matrix *m = new Matrix(size);
    
    if (n == 0)
    {
        m->iMatrix();
        return m;
    }
    m = this;
    
    for (int i=0; i<(n-1); i++)
        m = multMatrix(matrix,m->getMatrix());
    
    return m;
}

void Matrix::iMatrix()
{
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
        {
            if (i == j)
            {
                matrix[i][j].setReal(1);
                matrix[i][j].setImg(0);
            }
            else
            {
                matrix[i][j].setReal(0);
                matrix[i][j].setImg(0);
            }
        }
}

Matrix *Matrix::multMatrix(Complex **m1, Complex **m2)
{
    Matrix *res = new Matrix(size);
    Complex mulRes;
    Complex addRes;
    int i,j,k;
    
    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            addRes.setReal(0);
            addRes.setImg(0);
            for (k=0; k<size; k++)
            {
                mulRes = m1[i][k].mul(m2[k][j]);
                addRes = addRes.add(mulRes);
            }
            res->setValue(i,j,addRes);
        }
    }
    return res;
        
}

Complex Matrix::getComplex(int i,int j)
{
    return matrix[i][j];
}

void Matrix::print()
{
    cout << name << " = [" << endl;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            matrix[i][j].print();
            cout << ' ';
        }
    
        cout << endl;
    }
    cout << "]" << endl;
}

Complex **Matrix::getMatrix()
{
    return matrix;
}

Complex Matrix::computeDet(int n,Complex **c)
{
    
    if (n==2)
        return (c[0][0].mul(c[1][1])).sub(c[0][1].mul(c[1][0]));
    
    Complex d;
    int k, i, j, subi, subj;
    Complex **subMat = new Complex*[n];
    Complex scalar;
    for (int i=0; i<n; i++)
        subMat[i] = new Complex[n];
    
    for (k=0; k<n; k++)
    {
        subi=0;
        for(i = 1; i < n; i++)
        {  
            subj = 0;
            for(j = 0; j < n; j++)
            {    
                if (j == k)
                {
                    continue;
                }
                subMat[subi][subj] = c[i][j];
                subj++;
            }
            subi++;
        }
        scalar.setReal(pow(-1 ,k));
        scalar.mul(c[0][k]);
        scalar.mul(computeDet(n - 1 ,subMat));
        d = d.add(scalar);
    }
    return scalar;
}

