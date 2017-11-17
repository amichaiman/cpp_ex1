#include <iostream>
#include "matrix.h"
#include "complex.h"
#include "matrixList.h"

using namespace std;

void clearBuffer()      //clears buffer
{
    while(cin.get() != '\n' && cin.eof != true);
}


int main()
{
    List list;  //holds linked list head
    char input;   
    int choice;
    Matrix *m;
    const int INVALID_INPUT = 7;    //a number not associated with action
    
    list.head = NULL;
    
    
    while (true)
    {
        cin >> input;
        clearBuffer();
        
        if (isdigit(input))
            choice = input - '0';
        else
            choice = INVALID_INPUT;
        
        switch (choice)
        {
            case 0:
                return 0;
            case 1:         //add matrix 
            {
                m = getMatrix();
                if (m)
                {
                    addToList(list,m);
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
            } break;
            
            case 2:         //remove matrix
            {
                string name;
                cin >> name;
                if (isLegalName(name))
                {
                    if(!remove(list,name))
                        cout << "ERROR: " << name << " does not exist" << endl;
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
                
            } break;
            
            case 3:         //multiply matrix by scalar
            {
                string toMul;
                string comp;
                string res;
                Complex c;
                LinkedM *link;
                Matrix *m;
                
                cin >> toMul;
                cin >> comp;
                cin >> res;
                
                if(isLegalName(toMul) && c.parseComplex(comp) && isLegalName(res))
                {
                    
                    link = find(list.head,toMul);
                    if (link)
                    {
                        m = link->m->multByScalar(c);
                        m->setName(res);
                        
                        addToList(list,m);
                    }
                    else
                        cout << "ERROR: " << toMul << " does not exist" << endl;
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
            }break;
            
            case 4:                 //raise matrix to the power of 'power'
            {
                string toMul;
                int power;
                string res;
                LinkedM *link;
                
                cin >> toMul;
                cin >> power;
                cin >> res;
                
                if(isLegalName(toMul) && (power>=0) && isLegalName(res))
                {
                    
                    link = find(list.head,toMul);
                    if (link)
                    {
                        m = link->m->raiseToThePower(power);
                        m->setName(res);
                        
                        addToList(list,m);
                    }
                    else
                        cout << "ERROR: " << toMul << " does not exist" << endl;
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
            }break;
            
            case 5:         //compute matrix determinant
            {
                string toCompute;
                LinkedM *link;
                Complex det;
                cin >> toCompute;
                
                if(isLegalName(toCompute))
                {
                    link = find(list.head,toCompute);
                    if (link)
                    {
                        det = link->m->computeDet(link->m->getSize(),link->m->getMatrix());
                        
                        det.print();
                        cout << endl;
                    }
                    else
                        cout << "ERROR: " << toCompute << " does not exist" << endl;
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
            }break;
            
            case 6:         //printf specific matrix
            {
                LinkedM *link;
                string toPrint;
                cin >> toPrint;
                
                if(isLegalName(toPrint))
                {
                    
                    link = find(list.head,toPrint);
                    if (link)
                        link->m->print();
                    else
                        cout << "ERROR: " << toPrint << " does not exist" << endl;
                }
                else
                {
                    cout << "ERROR: invalid input" << endl;
                    clearBuffer();
                }
                
            }break;
            
            default:
                cout << "ERROR: invalid command; type 0 for exit" << endl;
        }
    }
    
}
