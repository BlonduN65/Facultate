#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;

struct AVL{
    int data;
    int bf;
    AVL *stg,*drt;
};
struct lista{
    int data;
    lista* next;
};
void afisare(lista* cap);
void inserare_frunze(lista* &cap,AVL* r);
void insert_lista(lista* &cap,int x);
void RSS(AVL* &r );
void RSD(AVL* &r);
void creare_avl(AVL* &r);
void RDD(AVL* &r);
void RSDD(AVL* &r);
void echilibrare(AVL* &r);
void insert(AVL* &r,int a);
void cheie_maxim(AVL* r);
void cheie_minim(AVL* r);

#endif