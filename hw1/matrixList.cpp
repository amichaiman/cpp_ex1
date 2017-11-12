#include "matrixList.h"

LinkedM *find(LinkedM *cur,string name)
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
    cin >> size;
    
    if (!isLegalName(name))
        return NULL;
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
                    clearBuffer();
                    return NULL;
                }
            if (j == size-1)
                if (cin.get() != '\n')
                {
                    clearBuffer();
                    return NULL;
                }
                
            if (!c.parseComplex(comp))
                return NULL;
            m->setValue(i,j,c);
        }
    m->setName(name);
    return m;
}

bool isLegalName(string name)
{
    for (unsigned int i=0; i<name.length(); i++)
        if (name[i] < 'A' || name[i] > 'Z')
            return false;
    return true;
}

void clearBuffer()
{
    while (cin.get() != '\n');
}


bool remove(List &l,string name)
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

void printList(List &l)
{
    LinkedM *cur = l.head;
    
    while (cur != NULL)
    {
        cur->m->print();
        cur = cur->next;
    }
}








