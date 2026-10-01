#include "header.h"

BST *creare_arbore(int cost,char nume[]){
    BST* r=new BST;
    r->pret=cost;
    strcpy(r->s,nume);
    r->stg=NULL;
    r->drt=NULL;
    return r;
}
void insert(BST* &r,int cost, char nume[]){
    if(r==NULL){
        r=creare_arbore(cost,nume);

    }
    else{
        if(cost<r->pret){
            insert(r->stg,cost,nume);
        }
        else{
            insert(r->drt,cost,nume);
        }
    }
}
void inorder(BST* r){
    if(r!=NULL){
        inorder(r->stg);
        cout<<r->pret<<" "<<r->s<<" "<<endl;
        inorder(r->drt);
    }
}
int f(char *key){
    int i,suma;
    suma=0;
    for(i=0;i<strlen(key);i++){
        suma=suma+key[i];
    }
    return suma%M;
}
void initializare(hash_t *HT[]){
    for(int i=0;i<M;i++)
        HT[i]=NULL;
}
void inserare(hash_t *HT[],char*key){
    
    int h=f(key);
    hash_t *nou=new hash_t;
    strcpy(nou->cheie,key);
    nou->urm=HT[h];
    HT[h]=nou;

}
void afisare_tabela(hash_t *HT[]){
    for(int i=0;i<M;i++){
        cout<<"Pozitia este ["<<i<<"]: ";
        hash_t *nou=HT[i];
        while(nou!=NULL){
            cout<<nou->cheie;
            nou=nou->urm;
        }
        cout<<endl;
    }
}

void adaugare(hash_t *HT[],BST* r){
    if(r!=NULL){
        if(r->pret<1000){
            inserare(HT,r->s);
        }
        adaugare(HT,r->stg);
        adaugare(HT,r->drt);
    }

}