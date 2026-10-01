#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <cstring>
using namespace std;
#define M 13
struct BST{
    char s[256];
    int pret;
    BST *stg,*drt;
};
struct hash_t{
    char cheie[256];
    struct hash_t *urm;
};


void adaugare(hash_t *HT[],BST* r);
void afisare_tabela(hash_t *HT[]);
int f(char *key);
void inserare(hash_t *HT[],char*key);
void initializare(hash_t *HT[]);
BST *creare_arbore(int cost,char nume[]);
void insert(BST* &r,int cost, char nume[]);
void inorder(BST* r);

#endif