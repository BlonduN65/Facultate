#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
using namespace std;
struct lista{
    int val;
    lista *urm;

};
void insert_lista(lista* &cap,int x);
void creare_lista(lista* &cap);
void afisare(lista* cap);
void valori_pare(lista* cap);
void heap_sort_descrescator(int heap[], int n);
void afisare_heap(int heap[], int n);
void creare_heap_din_lista(lista* cap, int heap[], int &n);
void cerne(int heap[], int n, int i);
void insereaza_heap(int heap[], int &n, int x) ;

#endif