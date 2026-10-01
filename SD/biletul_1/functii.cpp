#include "header.h"

BST *creare(int x){
    BST* r = new BST;
    r->info = x;
    r->stg = NULL;
    r->drt = NULL;
    return r;
}

void insert(BST* &r, int x){
    if(r == NULL)
        r = creare(x);
    else if(x > r->info)
        insert(r->drt, x);
    else
        insert(r->stg, x);
}

void init_coada(coada &c){
    c.prim = 0;
    c.ultim = 0;
}

int isEmpty(coada c){
    return (c.prim == c.ultim) ? 1 : 0;
}

int nextpoz(int index){
    if(index < 100) 
        return index + 1;
    else
        return 0;
}

int isFull(coada c){
    return (nextpoz(c.ultim) == c.prim) ? 1 : 0;
}

void put(coada &c, BST *nod){
    if(!isFull(c)){
        c.data[c.ultim] = nod;      // 1. Punem nodul
        c.ultim = nextpoz(c.ultim); // 2. Incrementăm circular
    }
}

BST* get(coada &c){
    if(!isEmpty(c)){
        BST* nod = c.data[c.prim];
        c.prim = nextpoz(c.prim);
        return nod;
    }
    return NULL;
}

void removeGreteast(BST* &r) {
    if (r == NULL) return; 
    if (r->drt != NULL) {
        removeGreteast(r->drt);
    } 
    else {
        BST* temp = r;
        r = r->stg;   
        delete temp;  
    }
}

void inserare_lista(lista* &cap, int x){
    lista* nou = new lista;
    nou->info = x;
    nou->urm = cap;
    cap = nou;
}

void creare_lista(lista* &cap, int x){
    lista* nou = new lista;
    nou->info = x;
    nou->urm = nullptr;
    if(cap == nullptr){
        cap = nou;
        return;
    }
    lista* nou2 = cap;
    while(nou2->urm != nullptr)
        nou2 = nou2->urm;
    nou2->urm = nou;
}

void afisare(lista* cap){
    if(cap == nullptr){
        cout << "Am ajuns la sfarsitul listei!\n";
    }
    else{
        cout << cap->info << " ";
        afisare(cap->urm);
    }
}

void colecteaza_impare(BST* r, lista* &cap){
    if(r == NULL) return; // Siguranță maximă împotriva crash-ului
    
    if(r->info % 2 != 0) { // Prinde și numerele negative impare
        creare_lista(cap, r->info);
    }
    colecteaza_impare(r->stg, cap);
    colecteaza_impare(r->drt, cap);
}