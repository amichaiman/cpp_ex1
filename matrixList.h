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

LinkedM *find(LinkedM *cur,const string name);  //returns pointer to desired node(searched by name).
void addToList(List &head,Matrix *m); //adds matrix to linked list
void replace(List &head, LinkedM *toReplace, LinkedM *toAdd); //replaces one node by the other
bool isLegalName(const string name); //returns true if all letters in 'name' are upper case
Matrix *getMatrix();    //recieves name of matrix, and values from user, and returns matrix if values given are legal, NULL otherwise
bool remove(List &l,const string name); //removes node from list(searched by name). returns true if found and removed, false otherwise
void printList(const List &l);  //prints all matrixs in list
#endif
