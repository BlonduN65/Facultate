#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
using namespace std;

struct nod{
    int valoare;
    nod* stg;
    nod* dr;
};
nod *creare_nod(int x);
void insert(nod* &r, int val);
nod *cautare(nod* r, int k);
nod *remove_greteast(nod* &r);
void delete_radacina(nod* &r);
void stergere(nod* r, int k);
void inorder(nod* r );
void preorder(nod* r);
void postoerder(nod* r);



#endif