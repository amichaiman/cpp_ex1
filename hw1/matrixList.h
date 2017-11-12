#ifndef _MATRIX_LIST
#define _MATRIX_LIST
#include <iostream>
#include "matrix.h"

using namespace std;
typedef struct LinkedM
{
    Matrix *m;
    struct LinkedM *next;
} LinkedM;

typedef struct List
{
    LinkedM *head;
} List;

LinkedM *find(LinkedM *cur,string name);
void addToList(List &head,Matrix *m);
void replace(List &head, LinkedM *toReplace, LinkedM *toAdd);
bool isLegalName(string name);
Matrix *getMatrix();
bool isLegalName(string name);
void clearBuffer();
bool remove(List &l,string name);
void printList(List &l);
#endif
