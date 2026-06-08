#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
using namespace std;

struct AVL{
    int data;
    int bf;
    AVL *stg,*drt;
};
void creare(AVL* &a);
void RSS(AVL* &a);
void RSD(AVL* &a);
void RDD(AVL* &a);
void RSDD(AVL* &a);
void echilibrare(AVL* &a);
void insert(AVL* &a,int x);
void deleteAVL(AVL* &a);
void inorder(AVL* &a);


#endif