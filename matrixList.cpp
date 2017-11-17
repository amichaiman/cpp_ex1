#include "matrixList.h"

LinkedM *find(LinkedM *cur,const string name)
{
    if (!cur)
        return NULL;
    if (cur->m->getName() == name)
        return cur;
    return find(cur->next,name);
}


void addToList(List &head,Matrix *m)
{
    remove(head,m->getName());
    LinkedM *toAdd = new LinkedM;
    toAdd->m = m;
    toAdd->next = head.head;
    head.head = toAdd;
}

void replace(List &head, LinkedM *toReplace, LinkedM *toAdd)
{
    LinkedM *cur = head.head;
    
    if (cur == toReplace)
    {
        toAdd->next = head.head->next;
        delete(head.head);
        head.head = toAdd;
        return;
    }
    
    while (cur->next != toReplace)
        cur = cur->next;
    
    toAdd->next = cur->next->next;
    delete(cur->next);
    cur->next = toAdd;
}

Matrix *getMatrix()
{
    string name;
    int size;
    
    cin >> name;
    if (!isLegalName(name))
        return NULL;
    
    cin >> size;
    
    
    if (size < 0)
        return NULL;
    
    Matrix *m = new Matrix(size);
    string comp;
    Complex c;
    
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
        {
            cin >> comp;
            if (j != size-1)
                if (cin.get() != ' ')
                {
                    cout.flush();
                    return NULL;
                }
            if (j == size-1)
                if (cin.get() != '\n')
                {
                    cout.flush();
                    return NULL;
                }
                
            if (!c.parseComplex(comp))
            {
                cout.flush();
                return NULL;
            }
            m->setValue(i,j,c);
        }
    m->setName(name);
    return m;
}

bool isLegalName(const string name)
{
    for (unsigned int i=0; i<name.length(); i++)
        if (name[i] < 'A' || name[i] > 'Z')
            return false;
    return true;
}



bool remove(List &l,const string name)
{
    LinkedM *cur = l.head;
    
    if (cur == NULL)
        return false;
    
    if (cur->m->getName() == name)
    {
        cur = cur->next;
        delete(l.head);
        l.head = cur;
        return true;
    }
    
    while (cur->next != NULL)
    {
        if (cur->next->m->getName() == name)
        {
            LinkedM *toDelete = cur->next;
            cur->next = toDelete->next;
            delete(toDelete);
            return true;
        }
        cur = cur->next;
    }   
    return false;
}

void printList(const List &l)
{
    LinkedM *cur = l.head;
    
    while (cur != NULL)
    {
        cur->m->print();
        cur = cur->next;
    }
}








