#include "header.h"


void inserare_nod(nod* &cap, int valoare){

    nod* nou=new nod;
    nou->val=valoare;
    nou->next=NULL;
    nou->prev=NULL;
    if (cap==nullptr){
        cap=nou;
        return;
    }

    nod* curent=cap;
    while(curent->next!=nullptr){
        curent=curent->next;

    }
    curent->next=nou;
    nou->prev=curent;

}
void afisare_stanga(nod* cap){
    cout<<"Afisare stanga dreapta";

        nod* curent=cap;
        while(curent!=NULL){
            cout<<curent->val<<" ";
            curent=curent->next;

        }
}

void afisare_dreapta(nod *cap){
    cout<<"afisare dreapta stanga ";
    nod* curent=cap;
    while(curent->next!=NULL)
        curent=curent->next;

    while(curent!=NULL){
        cout<<curent->val<<" ";
        curent=curent->prev;
    }
}