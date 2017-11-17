#include <iostream>
#include "md;

int main()
{
    List list;
    int choice;
    Matrix *m;
    
    list.head = NULL;
    
    cin.clear();
    
    
    cin >> choice;
    
    while (choice != 0)
    {
        switch (choice)
        {
            case 0:
                return 0;
            case 1:
            {
                m = getMatrix();
                if (m)
                {
                    addToList(list,m);
                    printList(list);
                }
                else
                    cout << "ERROR: invalid input" << endl;
                
            } break;
            
            case 2:
            {
                string name;
                cin >> name;
                if (isLegalName(name))
                {
                    if(!remove(list,name))
                        cout << "ERROR: " << name << " does not exist" << endl;
                }
                printList(list);
            } break;
            
            case 3:
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
                        printList(list);
                    }
                    else
                        cout << "ERROR: " << toMul << " does not exist" << endl;
                }
                else
                    cout << "ERROR: invalid input" << endl;
            }break;
            
            case 4:
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
                        printList(list);
                    }
                    else
                        cout << "ERROR: " << toMul << " does not exist" << endl;
                }
                else
                    cout << "ERROR: invalid input" << endl;
                
            }break;
            
            case 5:
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
                    cout << "ERROR: invalid input" << endl;
            }break;
            
            case 6:
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
                    cout << "ERROR: invalid input" << endl;
                
                
            }break;
            default:
                cout << "ERROR: invalid command; type 0 for exit" << endl;
        }
        cin >> choice;
    }
    
}
