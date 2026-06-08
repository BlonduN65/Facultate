#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
using namespace std;

struct nod{
    int val;
    nod *next;
    nod *prev;

};

void inserare_nod(nod* &cap, int valoare);
void afisare_stanga(nod* cap);
void afisare_dreapta(nod *cap);


#endif