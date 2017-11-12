#include "complex.h"


Complex Complex::sub(Complex c)
{
    Complex res;
    
    res.setReal(real - c.getReal());
    res.setImg(img - c.getImg());
    
    return res;
}
Complex Complex::add(Complex &c)
{
    Complex res;
    
    res.setReal(real + c.getReal());
    res.setImg(img + c.getImg());
    
    return res;
}

Complex Complex::mul(Complex c)
{
    Complex res;
    
    res.setReal(real*c.getReal() - img*c.getImg());
    res.setImg(real*c.getImg() + img*c.getReal());

    return res;
}


float Complex::getReal()
{
    return real;
}


float Complex::getImg()
{
    return img;
}

void Complex::setReal(float theReal)
{
    real = theReal;
}
void Complex::setImg(float theImg)
{
    img = theImg;
}
    
void Complex::print()
{
    int theReal = real*1000;
    int theImg = img*1000;
    
    setReal(theReal/1000.0);
    setImg(theImg/1000.0);
    cout <<"(" << real << "," << img << ")";
}

    
bool Complex::parseComplex(string comp)
{
    int i=1;
    bool decimal=false;
    int decimalCount=0;
    string s="";
    
    
    
    if ((comp[0] != '(') || (comp[comp.length()-1] != ')'))
        return false;
        
    while (comp[i] != ',')
    {
        if (isdigit(comp[i]) || comp[i] == '.' || comp[i] == '-' || comp[i] == '0')
        {            
            if (decimal==true)
                decimalCount++;

            if (comp[i] == '.')
                decimal=true;
            
            if (decimalCount<=3)
                s+=comp[i];
            i++;
        }
        else
            return false;
    }
    setReal(stof(s));
    
    decimalCount=0;
    decimal=false;
    s = "";
    i++;
    
    while (comp[i] != ')')
    {
        if (isdigit(comp[i]) || comp[i] == '.' || comp[i] == '-' || comp[i] == '0')
        {
            
            if (decimal==true)
                decimalCount++;

            if (comp[i] == '.')
                decimal=true;
                        
            if (decimalCount<=3)
                s+=comp[i];
            i++;
        }
        else
            return false;
        
    }
    setImg(stof(s));
    return true;
    
}
 
    
    


