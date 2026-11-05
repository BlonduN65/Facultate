#include "header.h"
#include <iostream>

int main() {
    int n = 0;
    int *v = citesteTablou(&n);

    if (v == nullptr) {
        std::cout << "Alocarea a esuat\n";
        return 1;
    }

    // Afișarea în ordine inversă
    for (int i = n - 1; i >= 0; i--) {
        std::cout << *(v + i) << " ";
    }
    std::cout << "\n"; // <-- ADAUGĂ ACEASTĂ LINIE pentru a forța afișarea pe ecran

    // Nu uita să eliberezi memoria alocată dinamic
    delete[] v;
    v = nullptr;

    return 0;
}


