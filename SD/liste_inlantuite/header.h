#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
using namespace std;

struct nod{
    int val;
    nod *next;

};

void inserare_nod(nod* &cap, int valoare);
void afisare(nod* cap);



#endif