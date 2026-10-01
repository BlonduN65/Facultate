#include "header.h"

void insert_lista(lista* &cap,int x){
    lista* p=new lista;
    p->val=x;
    p->urm=NULL;
    if(cap==NULL){
        cap=p;
        p->urm=cap;
    }
    lista* curent=cap;
    while(curent->urm!=cap){
        curent=curent->urm;
    }
    curent->urm=p;
    p->urm=cap;
}
void creare_lista(lista* &cap){
    int x;
    while(cin>>x && x!=0){
        insert_lista(cap,x);
    }
}
void afisare(lista* cap){
    if(cap == NULL) {
        cout << "Lista este goala." << endl;
        return;
    }
    lista* curent = cap;
    do {
        cout << curent->val << " ";
        curent = curent->urm;
    } while(curent != cap); // Te oprești când ai făcut un ocol complet
    cout << endl;
}
void valori_pare(lista* cap){
    if(cap == NULL) {
        cout << "Numarul de valori pare din lista este : 0" << endl;
        return;
    }
    lista* nou = cap;
    int contor = 0;
    do {
        if(nou->val % 2 == 0)
            contor++;
        nou = nou->urm;
    } while(nou != cap); // Previne bucla infinită
    
    cout << "Numarul de valori pare din lista este : " << contor << endl;
}

void insereaza_heap(int heap[], int &n, int x) {
    heap[n] = x;
    int i = n++;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 2. Cernere (filtrare în jos)
void cerne(int heap[], int n, int i) {
    int minim = i, stg = 2 * i + 1, drt = 2 * i + 2;
    if (stg < n && heap[stg] < heap[minim]) minim = stg;
    if (drt < n && heap[drt] < heap[minim]) minim = drt;
    if (minim != i) {
        swap(heap[i], heap[minim]);
        cerne(heap, n, minim);
    }
}

// 3. Extragere elemente pare din lista circulara
void creare_heap_din_lista(lista* cap, int heap[], int &n) {
    if (!cap) return;
    lista* curent = cap;
    do {
        if (curent->val % 2 == 0) insereaza_heap(heap, n, curent->val);
        curent = curent->urm;
    } while (curent != cap);
}

// 4. Sortare descrescătoare (HeapSort)
void heap_sort_descrescator(int heap[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        cerne(heap, i, 0); // i actioneaza direct ca noua dimensiune redusa
    }
}

// 5. Afișare vector
void afisare_heap(int heap[], int n) {
    for (int i = 0; i < n; i++) cout << heap[i] << " ";
    cout << endl;
}