#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;

struct BST{
    int info;
    BST *stg;
    BST *drt;

};
struct coada{
    BST* data[101];
    int prim,ultim;
};
struct lista{
    int info;
    lista *urm;
};

BST *creare(int x);
void insert(BST* &r,int x);

void init_coada(coada &c);
int nextpoz(int index);
int isFull(coada c);
void put(coada &c,BST *nod);
int isEmpty(coada c);

BST* get(coada &c);

void removeGreteast(BST* &r);

void inserare_lista(lista* &cap,int x);
void afisare(lista* cap);
void creare_lista(lista* &cap,int x);
void colecteaza_impare(BST* r,lista* &cap);
#endif