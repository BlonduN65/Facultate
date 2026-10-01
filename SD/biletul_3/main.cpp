#include "header.h"

int main() {
    BST* radacina = NULL;
    hash_t* tabela_hash[M];
    initializare(tabela_hash);

    // Inserăm câteva produse de test în BST
    insert(radacina, 500, "Laptop");
    insert(radacina, 1500, "Telefon-Scump");
    insert(radacina, 250, "Tastatura");
    insert(radacina, 1200, "Monitor");
    insert(radacina, 50, "Mouse");

    cout << "--- Afisare BST in Inordine (ordonat dupa pret) ---" << endl;
    inorder(radacina);
    cout << endl;

    // Filtrează produsele cu preț < 1000 și le pune în tabela hash
    adaugare(tabela_hash, radacina);

    cout << "--- Tabela Hash (Produse cu pret < 1000) ---" << endl;
    afisare_tabela(tabela_hash);

    return 0;
}