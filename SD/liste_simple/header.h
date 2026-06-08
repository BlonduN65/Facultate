#ifndef HEDAER_H
#define HEDAER_H

#include <iostream>
using namespace std;

struct Nod{

    int info;
    Nod* next;

};
void afisare_Lista(Nod* cap);
void inserare_inceput(Nod* &cap , int valoare);
void inserare_final(Nod* &cap , int valoare);
void inserare_dupapoz(Nod* cap, int valorare,int poz);
void cautare_element(Nod* cap , int element);


#endif
