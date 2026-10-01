#include "header.h"

int  main(){
    BST* r = NULL;
    coada c; // MODIFICAT: obiect normal, nu pointer (fără *)
    int x;

    cout << "Dati valori pana la citirea lui 0: ";
    while(cin >> x && x != 0){
        insert(r, x);
    }
    removeGreteast(r); 
    BST* copie=r;
    
    // MODIFICAT: Toată logica de afișare pe niveluri reparată aici
    if (r != NULL) {
        init_coada(c);
        put(c, r); // Punem rădăcina în coadă

        cout << "Afisare pe niveluri: ";
        while(!isEmpty(c)){
            BST* curent = get(c); // Scoatem nodul curent
            cout << curent->info << " "; // Îi afișăm valoarea
            
            // Punem copiii lui în coadă pentru nivelul următor
            if(curent->stg != NULL) 
                put(c, curent->stg);
            if(curent->drt != NULL) 
                put(c, curent->drt);
        }
        cout << "\n";
    }       
    lista* cap=nullptr;
    colecteaza_impare(copie,cap);
    cout<<"Afisare lista ";
    afisare(cap);
    return 0;   
}