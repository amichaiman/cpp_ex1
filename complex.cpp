#include "complex.h"


Complex Complex::sub(const Complex c) const
{
    Complex res;
    
    res.setReal(real - c.getReal());
    res.setImg(img - c.getImg());
    
    return res;
}
Complex Complex::add(const Complex &c) const
{
    Complex res;
    
    res.setReal(real + c.getReal());
    res.setImg(img + c.getImg());
    
    return res;
}

Complex Complex::mul(const Complex c) const
{
    Complex res;
    
    res.setReal(real*c.getReal() - img*c.getImg());
    res.setImg(real*c.getImg() + img*c.getReal());

    return res;
}


float Complex::getReal() const
{
    return real;
}


float Complex::getImg() const
{
    return img;
}

void Complex::setReal(const float theReal)
{
    real = theReal;
}
void Complex::setImg(const float theImg)
{
    img = theImg;
}
    
void Complex::print()
{
    int theReal = real*1000;        //move floating point 3 digits to the right, and casting it to an integer
    int theImg = img*1000;      
    
    setReal(theReal/1000.0);    //move floating point 3 digits to the left
    setImg(theImg/1000.0);
    cout <<"(" << real << "," << img << ")";
}

    
bool Complex::parseComplex(string comp)
{
    
    if (comp[0] != '(' || comp[comp.length()-1] != ')')
        return false;
    
    string s = "";
    int i = 1;
    
    while (comp[i] != ',')
    {
        if (isdigit(comp[i]) == true || comp[i] == '-' || comp[i] == '.')
            s+=comp[i++];
        else
            return false;
    }
    real = atof(s.c_str());
    s = "";
    i++;
    while (comp[i] != ')')
    {
        if (isdigit(comp[i]) == true || comp[i] == '-' || comp[i] == '.')
            s+=comp[i++];
        else
            return false;
    }
    img = atof(s.c_str());
    return true;
    
}
 
    
    


