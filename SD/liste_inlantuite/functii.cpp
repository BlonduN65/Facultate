#include "header.h"

void inserare_nod(nod* &cap, int valoare){

    nod* nou=new nod;
    nou->val=valoare;
    if(cap==nullptr){
        cap=nou;
        nou->next=cap;
        return;

    }

    nod* curent=cap;
    while(curent->next!=cap){

        curent=curent->next;

    }
    curent->next=nou;
    nou->next=cap;


}
void afisare(nod *cap){
    if (cap==nullptr){
        cout<<"Lista este goala ";
        return;
    }
    nod *curent=cap;
    do{
        cout<<curent->val<<" ";
        curent=curent->next;

    }while(curent!=cap);


}
