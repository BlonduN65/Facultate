#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;
#define DIMax 200
typedef int Atom;

struct coada{
    Atom v[DIMax];
    int prim , ultim;    
};

void initCoada(coada &c);
int isEmpty(coada c);
int isFull(coada c);
void put(coada &c, int x);
Atom get(coada &c);
Atom front(coada c);



#endif